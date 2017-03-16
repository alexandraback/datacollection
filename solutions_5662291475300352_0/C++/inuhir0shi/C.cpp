


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


int main(){
    cout.setf(ios::fixed); cout.precision(10);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int caseNum = 1; caseNum <= T; caseNum++) { 
        int N;
        cin >> N;
        int ans = 0;
        vector<int> D(N), H(N), M(N);
        for (int i = 0; i < N; i++) {
            cin >> D[i] >> H[i] >> M[i];
        }
        if (N == 1) ans = 0;
        else {
            if (D[0] < D[1]) {
                swap(D[0], D[1]);
                swap(H[0], H[1]);
                swap(M[0], M[1]);
            }
            vector<double> T1(N), T2(N);
            for (int i = 0; i < N; i++) {
                T1[i] = (360.0-D[i]) / 360.0 * M[i];
                T2[i] = (720.0-D[i]) / 360.0 * M[i];
            }
            if (T2[1] < T1[0] || T2[0] < T1[1]) ans = 1;
            else ans = 0;
        }
        cout << "Case #" << caseNum << ": " << ans << endl;
    }
    return 0;
}
