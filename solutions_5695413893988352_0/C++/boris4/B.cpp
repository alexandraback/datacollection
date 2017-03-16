#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string C, J;
long long bestDiff;
string bestC;
string bestJ;

long long myabs(long long a) {
    if (a < 0) return -a;
    return a;
}

long long getNum(string s) {
    int n = s.size();
    long long res = 0;
    for (int i = 0; i < n; ++i)
        res = res * 10 + s[i] - '0';
    return res;
}

pair<long long, pair<string, string> > calc() {
    if (C == J) {
        string nC = C;
        string nJ = J;
        int n = nC.size();
        for (int i = 0; i < n; ++i) {
            if (nC[i] == '?') nC[i] = '0';
            if (nJ[i] == '?') nJ[i] = '0';
        }
        return make_pair(0, make_pair(nC, nJ));
    }
    int state = C < J;
    string nC = C;
    string nJ = J;
    int n = nC.size();
    for (int i = 0; i < n; ++i) {
        if (nC[i] == '?') nC[i] = 9*state + '0';
        if (nJ[i] == '?') nJ[i] = 9*(1 - state) + '0';
    }
    long long numC = getNum(nC);
    long long numJ = getNum(nJ);
    return make_pair(myabs(numC - numJ), make_pair(nC, nJ));
}

void updateRes() {
    auto cur = calc();
    auto diff = cur.first;
    auto curRes = cur.second;
    if (bestDiff == -1 || diff < bestDiff ||
        (diff == bestDiff && (curRes.first < bestC ||
         (curRes.first == bestC && curRes.second < bestJ)))) {
        bestDiff = diff;
        bestC = curRes.first;
        bestJ = curRes.second;
    }
}

int main() {
    int testNum; cin >> testNum;
    for (int testId = 1; testId <= testNum; ++testId) {
        bestDiff = -1;
        bestC = "";
        bestJ = "";
        cout << "Case #" << testId << ": ";
        cin >> C >> J;
        int n = C.size();
        for (int i = 0; i < n; ++i) {
            char cc = C[i];
            char cj = J[i];
            if (cc == '?' && cj == '?') {
                C[i] = '0'; J[i] = '1';
                updateRes();
                C[i] = '1'; J[i] = '0';
                updateRes();
                C[i] = '0'; J[i] = '0';
            } else if (cc == '?') {
                if (J[i] != '0') {
                    C[i] = J[i] - 1;
                    updateRes();
                }
                if (J[i] != '9') {
                    C[i] = J[i] + 1;
                    updateRes();
                }
                C[i] = J[i];
            } else if (cj == '?') {
                if (C[i] != '0') {
                    J[i] = C[i] - 1;
                    updateRes();
                }
                if (C[i] != '9') {
                    J[i] = C[i] + 1;
                    updateRes();
                }
                J[i] = C[i];
            } else if (cc != cj) {
                break;
            }
        }
        updateRes();
        cout << bestC << " " << bestJ << endl;
    }
    return 0;
}
