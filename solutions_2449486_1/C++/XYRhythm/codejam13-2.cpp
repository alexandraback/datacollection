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

string isPos (const vector<vector<int>> &lawn, const int &N, const int &M) {
    vector<int> rows(N, 0);
    vector<int> cols(M, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            rows[i] = max(rows[i], lawn[i][j]);
            cols[j] = max(cols[j], lawn[i][j]);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (lawn[i][j] < rows[i] && lawn[i][j] < cols[j]) return "NO";
        }
    }
    return "YES";
}

int main() {
    //const char* input_file = "atest.txt";
    //const char* input_file = "asmall.in";
    const char* input_file = "alarge.in";
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
                //int para[2] = {0};
                //getline(fin, line);
                //stringToArray(line, 2, para);
                int N = 0, M = 0;
                fin >> N >> M;
                vector<vector<int>> lawn(N, vector<int>(M, 0));
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < M; ++j) {
                        fin >> lawn[i][j];
                    }
                }
                string res = isPos(lawn, N, M);
                linenum += N;
                cnum++;
                if (fout.good()) fout << "Case #" << cnum << ": " << res << endl;
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
