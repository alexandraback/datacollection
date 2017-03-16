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

long long getGain(const vector<int> &v, const vector<int> &vals) {
    long long res=0;
    for (int i=0; i<v.size(); ++i) {
        res += v[i]*vals[i];
    }
    return res;
}

int getEnergy (const int E, const int R, const vector<int> &v) {
    int res=E;
    for (int i=0; i<v.size(); ++i) res = min(E, res-v[i]+R);
    return res;
}

long long getRes(const int E, const int R, const vector<int> &vals) {

    int N = vals.size();
    if (R>=E){
        vector<int> v(N,E);
        return getGain(v, vals);
    }
    queue<vector<int>> que;
    que.push(vector<int>(0,0));
    long long res = 0;
    while (!que.empty()) {
        vector<int> pre = que.front();
        que.pop();
        if (pre.size() == N) {
                //for (int i=0; i<N; ++i) cout << pre[i];
                //cout << endl;
                res = max(res, getGain(pre, vals));
        }
        else {
            for (int i=0; i<=getEnergy(E, R, pre); ++i) {
                vector<int> tmp = pre;
                tmp.push_back(i);
                que.push(tmp);
            }
        }
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


                int E = 0, R = 0, N  = 0;
                fin >> E >> R >> N;
                vector<int> vals(N, 0);
                for (int i = 0; i < N; ++i) fin >> vals[i];
                long long res = getRes(E, R, vals);


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
