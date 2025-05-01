#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    cout << "Enter a password: ";
    cin >> password;

    // Create a file for the user in the database
    ofstream file(username + ".txt");
    if (file.is_open()) {
        file << username << endl;
        file << password << endl;
        file.close();
        cout << "Registration successful!" << endl;
    } else {
        cout << "Unable to create file!" << endl;
    }
}

// Function to login an existing user
void loginUser() {
    string username, password;

    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    cin >> password;

    // Check if the user exists in the database
    ifstream file(username + ".txt");
    if (file.is_open()) {
        string storedUsername, storedPassword;
        getline(file, storedUsername);
        getline(file, storedPassword);

        if (username == storedUsername && password == storedPassword) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid username or password!" << endl;
        }
        file.close();
    } else {
        cout << "User not found!" << endl;
    }
}

int main() {
    int choice;
    cout << "Login and Registration System" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
