#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;


int main() {
    string filename ("input_d");
    string line;
    ifstream file (filename);
    int k;

    //
    getline (file, line);
    k = stoi(line);

    for (int t = 0; t < k; t++) {   //for each test case
        int X, R, C;
        bool Gwin;

        // parsing
        getline (file, line);
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                X = stoi(line.substr(0, i));
                line = line.substr(i + 1, line.size() - i - 1);
                break;
            }
        }
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                R = stoi(line.substr(0, i));
                C = stoi(line.substr(i + 1, line.size() - i - 1));
                break;
            }
        }

        if (X == 1) Gwin = true;
        else if ((R*C)%X != 0) Gwin = false;
        else if (X == 2) Gwin = true;
        else if (X == 3) {
            if (R > 1 && C > 1) Gwin = true;
            else Gwin = false;
        } else if (X == 4) {
            if (R > 2 && C > 2 && max(R, C) >= 4) Gwin = true;
            else Gwin = false;
        } else if (X == 5) {
            if (R > 2 && C > 2 && R*C > 15) Gwin = true;
            else Gwin = false;
        } else if (X == 6) {
            if (R > 3 && C > 3 && max(C, R) >= 6) Gwin = true;
            else Gwin = false;
        } else Gwin = false;
        
        if (Gwin) {
            cout << "Case #" << t+1 << ": " << "GABRIEL" << "\n";
        } else {
            cout << "Case #" << t+1 << ": " << "RICHARD" << "\n";
        }
    }

    return 0;
}
