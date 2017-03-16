

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
template<class T> inline bool amax (T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool amin (T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> ostream& operator << (ostream &os, const vector<T> &v) { os << "["; for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); it++) { os << (it != v.begin() ? ", " : "") << *it; } os << "]"; return os; }
template<class T> ostream& operator << (ostream &os, const set<T> &s) { os << "["; for (typename set<T>::const_iterator it = s.begin(); it != s.end(); it++) { os << (it != s.begin() ? ", " : "") << *it; } os << "]"; return os; }
template<class Key, class Val> ostream& operator << (ostream &os, const map<Key, Val> &m) { os << "{"; for (typename map<Key, Val>::const_iterator it = m.begin(); it != m.end(); it++) { os << (it != m.begin() ? ", " : "") << it->first << ":" << it->second; } os << "}"; return os; }
template<class T, class S> ostream& operator << (ostream &os, const pair<T, S> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template <class Target, class Source> inline Target lexical_cast (const Source &s) { Target t; stringstream ss; ss << s; ss >> t; return t; }

//> v < ^ (clock wise)
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
const int INFI = 1<<28;
const long long int INFL = 1LL<<60;
const double INFD = 1e+300;
const float INFF = 1e+100;
const double EPS = 1e-8;


int banana;
void dfs (int &ans, int &total, int S, const string &target, const string &keyboard, string typed) {
    if (typed.size() == S) {
        total++;
        int instance = 0;
        for (int i = 0; i + target.size() <= S; i++) {
            if (typed.substr(i, target.size()) == target) {
                instance++;
            }
        }
        banana = max(banana, instance);
        ans += instance;
        return;
    }
    for (int i = 0; i < keyboard.size(); i++) {
        dfs(ans, total, S, target, keyboard, typed+keyboard[i]);
    }
}

int main(){
    cout.setf(ios::fixed); cout.precision(10);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int K, L, S;
        cin >> K >> L >> S;
        string keyboard;
        string target;
        cin >> keyboard >> target;
        int ans = 0;
        int total = 0;
        banana = 0;
            string begin;
            dfs(ans, total, S, target, keyboard, begin);
            cout << "Case #" << caseNum << ": " << banana - ans / static_cast<double>(total)  << endl;
            //cout << "Case #" << caseNum << ": " << 0.000000000  << endl;
    }
    return 0;
}
