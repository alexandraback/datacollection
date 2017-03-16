#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
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

long long getRes(long long r, long long t) {
    double tmp = (sqrt((2.0*r-1)*(2*r-1)+8*t) - (2*r-1)) / 4;
    long long res = tmp, res1 = res;
    long long flag = 2*r*res+res*(2*res-1)-t;
    if (flag > 0) {
        while (flag > 0) {
            res1--;
            flag = 2*r*res1+res1*(2*res1-1)-t;
        }
        res = res1;
    } else if (flag < 0) {
        while (flag <= 0) {
            res1++;
            flag = 2*r*res1+res1*(2*res1-1)-t;
        }
        res = res1-1;
    }
    return res;
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
                fin >> casenums;
            } else {
                if (cnum >= casenums) break;


                long long r = 0, t = 0;
                fin >> r >> t;

                int res = getRes(r, t);


                linenum ++;
                cnum++;
                cout << cnum << endl;
                if (fout.good()) fout << "Case #" << cnum << ": " << res << endl;
                //if (fout.good()) fout << "Case #" << cnum << ": " << setiosflags(ios::fixed) << setprecision(6) << res << endl;
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
