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

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

void openFiles() {
    //freopen("test.in", "rt", stdin);
    //freopen("test.out", "wt", stdout);
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt1.out", "wt", stdout);
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

long long toll(const string& w1) {
    stringstream ss;
    ss << w1 << endl;
    long long x;
    ss >> x;
    return x;
}

pair<string, string> change(string big, string small) {
    int n = big.size();
    bool go = false;
    REP(j, n) {
        if (big[j] != small[j] && big[j] != '?' && small[j] != '?') {
            go = true;
        }
        if (big[j] == '?' && small[j] == '?') {
            if (go) {
                big[j] = '0';
                small[j] = '9';
            } else {
                big[j] = '0';
                small[j] = '0';
            }
        } else if (big[j] == '?') {
            if (go) {
                big[j] = '0';
            } else {
                big[j] = small[j];
            }
        } else if (small[j] == '?') {
            if (go) {
                small[j] = '9';
            } else {
                small[j] = big[j];
            }
        }
    }
    return make_pair(big, small);
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "[" << p.first << ", " << p.second << "]";
    return os;
}


void solve() {
	string line; getline(cin, line);
    vector<string> tokens = tokenize(line);
    string coders = tokens[0];
    string jamers = tokens[1];
    vector<string> v1, v2;
    const long long INF = (1LL << 62);
    long long diff = INF, minc = INF, minj = INF;
    string s1, s2;
    static int ntest = 0;
    ++ntest;
    //cout << v1 << " " << v2 << endl;
    int len = coders.size();
    REP(i, len) {
        REP(j, len) REP(k, 3) {
            // 0 - equal, 1 => k1 > k2, 2 => k2 > k1
            string w1 = coders;
            string w2 = jamers;
            if (i != j) {
                continue;
            } else if (i == j) {
                if (w1[j] == '?' && w2[j] == '?') {
                    if (k == 0) {
                        w1[j] = '0'; w2[j] = '0';
                    } else if (k == 1) {
                        w1[j] = '1'; w2[j] = '0';
                    } else if (k == 2) {
                        w1[j] = '0'; w2[j] = '1';
                    }
                } else if (w2[j] == '?') {
                    if (k == 0) {
                        w2[j] = w1[j];
                    } else if (k == 1 && w1[j] != '0') {
                        w2[j] = w1[j] - 1;
                    } else if (k == 2 && w1[j] != '9') {
                        w2[j] = w1[j] + 1;
                    }
                } else if (w1[j] == '?') {
                    if (k == 0) {
                        w1[j] = w2[j];
                    } else if (k == 1 && w2[j] != '0') {
                        w1[j] = w2[j] - 1;
                    } else if (k == 2 && w2[j] != '9') {
                        w1[j] = w2[j] + 1;
                    }
                }
            }
            // if (ntest == 6)
            //     cerr << w1 << " " << w2 << endl;
            string x1 = w1, x2 = w2;
            REP(z, x1.size()) {
                if (x1[z] == '?') x1[z] = '0';
                if (x2[z] == '?') x2[z] = '0';
            }
            long long n1 = toll(x1);
            long long n2 = toll(x2);
            //cout << ":: " << n1 << " " << n2 << endl;
            if (n1 > n2) {
                pair<string, string> p = change(w1, w2);
                w1 = p.first;
                w2 = p.second;
            } else if (n2 > n1) {
                pair<string, string> p = change(w2, w1);
                w2 = p.first;
                w1 = p.second;
            } else {
                pair<string, string> p = change(w1, w2);
                w1 = p.first;
                w2 = p.second;
            }
            //cout << w1 << " " << w2 << endl;
            n1 = toll(w1);
            n2 = toll(w2);
            
            /* Compare. */
            bool better = false;
            long long newdiff = abs(n1 - n2);
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
                s1 = w1;
                s2 = w2;
                diff = newdiff;
                minc = n1;
                minj = n2;
            }
        }

        

    }
 
    printf("%s %s\n", s1.c_str(), s2.c_str());
}
int main() {
    openFiles();    
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {       
            cerr << i << endl; 
            printf("Case #%d: ", i + 1);
            solve();
    }
    return 0;
}
