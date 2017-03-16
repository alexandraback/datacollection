#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

class quat_class {
private:
    vector<string> table;
    int signs[4][4];
    int get_idx (char c) {
        if (c == '1') return 0;
        else return (c - 'h');
    }
public:
    quat_class(void) {
        table.push_back("1ijk");
        table.push_back("i1kj");
        table.push_back("jk1i");
        table.push_back("kji1");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                signs[i][j] = 1;
            }
        }
        signs[1][1] = -1;
        signs[1][3] = -1;
        signs[2][1] = -1;
        signs[2][2] = -1;
        signs[3][2] = -1;
        signs[3][3] = -1;
    }

    char multiply (string str, int *sign) {
        char c = str[0];
        char next;

        for (long long i = 1; i < str.length(); i++) {
            next = str[i];
            *sign = *sign * signs[get_idx(c)][get_idx(next)];
            c = table[get_idx(c)][get_idx(next)];
        }
        return c;
    }
};

int main() {
    string filename ("input_c");
    string line;
    ifstream file (filename);
    quat_class quat;
    int k;

    //
    getline (file, line);
    k = stoi(line);
    vector<string> table;
    int signs[4][4];
    int get_idx (char c) {
        if (c == '1') return 0;
        else return (c - 'h');
    }
public:
    quat_class(void) {
        table.push_back("1ijk");
        table.push_back("i1kj");
        table.push_back("jk1i");
        table.push_back("kji1");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                signs[i][j] = 1;
            }
        }
        signs[1][1] = -1;
        signs[1][3] = -1;
        signs[2][1] = -1;
        signs[2][2] = -1;
        signs[3][2] = -1;
        signs[3][3] = -1;
    }

    char multiply (string str, int *sign) {
        char c = str[0];
        char next;

        for (long long i = 1; i < str.length(); i++) {
            next = str[i];
            *sign = *sign * signs[get_idx(c)][get_idx(next)];
            c = table[get_idx(c)][get_idx(next)];
        }
        return c;
    }
};

int main() {
    string filename ("input_c");
    string line;
    ifstream file (filename);
    quat_class quat;
    int k;

    //
    getline (file, line);
    k = stoi(line);

    for (int t = 0; t < k; t++) {   //for each test case
        bool res = false;
        bool res = false;
        int sign = 1;
        long long L, X;
        string input;

        // parsing
        getline (file, line);
        for (long long i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                L = stoi(line.substr(0, i));
                X = stoi(line.substr(i+1, line.size()-i-1));
                break;
            }
        }

        getline (file, line);
        for (long long i = 0; i < X; i++) {
            input += line;
        }

        //
        if (input.length() >= 3 && quat.multiply(input, &sign) == '1' && sign == -1) {
            for (long long i = 1; i < input.length() - 1; i++) {
                int sign1 = 1;
                if (quat.multiply(input.substr(0, i), &sign1) != 'i' || sign1 == -1)
                    continue;
                for (long long j = i+1; j < input.length(); j++) {
                    int sign2 = 1;
                    int sign3 = 1;
                    if (quat.multiply(input.substr(i, j-i), &sign2) != 'j'
                        || sign2 == -1)
                        continue;

                    if (quat.multiply(input.substr(j, input.length() - j), &sign3) != 'k'
                        || sign3 == -1)
                        continue;

                    res = true;
                    break;
                }
            }
        }

        if (res) {
            cout << "Case #" << t+1 << ": " << "YES" << "\n";
        } else {
            cout << "Case #" << t+1 << ": " << "NO" << "\n";
        }

        //cout << "L: " << L << ", X: " << X << "\n";
    }

    return 0;
}