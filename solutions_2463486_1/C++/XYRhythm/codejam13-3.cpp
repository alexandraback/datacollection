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

vector<int> sets;

bool isPan (const long long &num) {
    long long n = num;
    string s;
    ostringstream convert;
    convert << n;
    s = convert.str();
    string s1 (s.rbegin(), s.rend());
    return s == s1;
}

void getSets(vector<long long> &v, const long long &maxnum) {
    long long th = sqrt(maxnum) + 1;
    for (long long i = 1; i < th; ++i) {
        if (isPan(i) && isPan(i*i)) v.push_back(i*i);
    }
}

long long getCount(const vector<long long> &v, const long long &start, const long long &end) {
    long long high = v.size(), res = 0;
    for (long long i = 0; i < high; ++i) {
        if (v[i] >= start && v[i] <= end) res++;
        if (v[i] > end) break;
    }
    return res;
}

int main() {
    //const char* input_file = "atest.txt";
    //const char* input_file = "asmall.in";
    const char* input_file = "alarge.in";
    const char* output_file = "aout.out";
    ifstream fin(input_file);
    ofstream fout(output_file);

    vector<long long> sets;
    getSets(sets, pow(10,14));
    //for (int i = 0; i < sets.size(); ++i) cout << sets[i] << endl;

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
                long long start = 0, end = 0;
                fin >> start >> end;
                long long res = getCount(sets, start, end);
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
