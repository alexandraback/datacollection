#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int stringToInt (const string &text) {
    stringstream ss(text);
    int res;
    return ss >> res ? res : 0;
}

template <typename T>
void stringToArray(const string &text, const int &size, T nums[]) {
    string tmp = "";
    int counter = 0;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            nums[counter] = (T) stringToInt(tmp);
            counter++;
            tmp = "";
        }
        else tmp += text[i];
    }
    nums[counter] = (T) stringToInt(tmp);
}
const string RES[4] = {"X won", "O won", "Draw", "Game has not completed"};

bool isX (string s) {
    bool r = true;
    for (int i = 0; i < 4; ++i) r = r && (s[i] == 'X' || s[i] == 'T');
    return r;
}

bool isO (string s) {
    bool r = true;
    for (int i = 0; i < 4; ++i) r = r && (s[i] == 'O' || s[i] == 'T');
    return r;
}

bool isemp (string s) {
    bool r = false;
    for (int i = 0; i < 4; ++i) r = r || s[i] == '.';
    return r;
}

int getRes(string b[]) {
    int emptyChar = false;
    // check rows
    for (int i = 0; i < 4; ++i) {
        if (isX(b[i])) return 0;
        if (isO(b[i])) return 1;
        if (isemp(b[i])) emptyChar = true;
    }

    // check cols
    for (int i = 0; i < 4; ++i) {
        string s = "";
        for (int j = 0; j < 4; ++j) s += b[j][i];
        if (isX(s)) return 0;
        if (isO(s)) return 1;
        if (isemp(s)) emptyChar = true;
    }

    // check two diagonals
    string s1 = "", s2 = "";
    for (int i = 0; i < 4; ++i) {
        s1 += b[i][i];
        s2 += b[i][3-i];

    }
    if (isX(s1)) return 0;
    if (isX(s2)) return 0;
    if (isO(s1)) return 1;
    if (isO(s2)) return 1;
    if (isemp(s1)) emptyChar = true;
    if (isemp(s2)) emptyChar = true;
    return emptyChar ? 3 : 2;
}

int main() {
    //const char* input_file = "atest.txt";
    const char* input_file = "asmall.in";
    //const char* input_file = "alarge.in";
    const char* output_file = "aout.out";
    ifstream fin(input_file);
    ofstream fout(output_file);

    int casenums = 0, cnum = 0;

    if (fin.is_open()) {
        int linenum = 0;
        string line;
        while (fin.good()) {
            if (linenum == 0) {
                getline(fin, line);
                casenums = stringToInt(line);
            } else {
                if (cnum >= casenums) break;
                string board[4] = {""};
                for (int i = 0; i < 4; ++i) {
                    getline(fin, line);
                    board[i] = line;
                }
                cnum++;
                linenum += 4;
                int status = getRes(board);
                getline(fin, line);
                if (fout.good()) fout << "Case #" << cnum << ": " << RES[status] << endl;
                else cout << "I/O error when writting into " << output_file << endl;
            }
            linenum++;
        }
        fin.close();
    }
    else cout << "Unable to open " << input_file << endl;

    fout.close();
    return 0;
}
