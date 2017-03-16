#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <list>
#include <sstream>
using namespace std;

void openFiles() {
    // freopen("test.in", "rt", stdin);
    // freopen("test.out", "wt", stdout);
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.out", "wt", stdout);
	// freopen("B-large.in", "rt", stdin);
	// freopen("B-large.out", "wt", stdout);
}

vector<string> tokenize(const string& line) {
    vector<string> tokens;
    stringstream ss(line);
    string s;
    while (ss >> s) tokens.push_back(s);
    return tokens;
}

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

void recur(vector<string>& comb, string& score, int idx) {
    if (idx == score.size()) {
        comb.push_back(score);
        return;
    }
    if (score[idx] == '?') {
        for (int i = 0; i < 10; i++) {
            score[idx] = (char)(i + '0');
            recur(comb, score, idx + 1);
        }
        score[idx] = '?';
    } else {
        recur(comb, score, idx + 1);
    }
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os<<"[";for(int i=0;i<v.size();i++)os<<" "<<v[i];os<<" ]";
    return os;
}

void solve() {
	string line; getline(cin, line);
    vector<string> tokens = tokenize(line);
    string coders = tokens[0];
    string jamers = tokens[1];
    vector<string> v1, v2;
    recur(v1, coders, 0);
    recur(v2, jamers, 0);
    const int INF = 0x7FFFFFFF;
    int diff = INF, minc = INF, minj = INF;
    string s1, s2;
    //cout << v1 << " " << v2 << endl;
    REP(i, v1.size()) REP(j, v2.size()) {
        int n1 = atoi(v1[i].c_str());
        int n2 = atoi(v2[j].c_str());
        bool better = false;
        int newdiff = abs(n1 - n2);
        if (newdiff < diff) {
            better = true;
        } else if (newdiff == diff) {
            if (n1 < minc) {
                better = true;
            } else if (n1 == minc) {
                if (n2 < minj) {
                    better = true;
                }
            }
        }
        if (better) {
            s1 = v1[i];
            s2 = v2[j];
            diff = newdiff;
            minc = n1;
            minj = n2;
        }
    }
    printf("%s %s\n", s1.c_str(), s2.c_str());
}

int main() {
    openFiles();
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
            printf("Case #%d: ", i + 1);
            solve();
    }
    return 0;
}
