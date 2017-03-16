#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define RREP(i,s,e) for (i = s; i >= e; i--)
#define rrep(i,n) RREP(i,(int)(n)-1,0)
#define REP(i,s,e) for (i = s; i <= e; i++)
#define rep(i,n) REP(i,0,(int)(n)-1)
#define INF 100000000

typedef long long ll;

vector<int> ansj;
vector<int> ansp;
vector<int> anss;

int jp[11][11];
int js[11][11];
int ps[11][11];

void solve(int test) {
    int i, j, k, J, P, S, K;
    cin >> J >> P >> S >> K;
    ansj.clear(); ansp.clear(); anss.clear();
    REP (i,1,J) REP (j,1,P) jp[i][j] = K;
    REP (i,1,J) REP (j,1,S) js[i][j] = K;
    REP (i,1,P) REP (j,1,S) ps[i][j] = K;
    REP (i,1,J) REP (j,1,P) rep (k,S) {
        int x = (j+k-1) % S + 1;
        if (jp[i][j] && js[i][x] && ps[j][x]) {
            jp[i][j]--;
            js[i][x]--;
            ps[j][x]--;
            ansj.push_back(i);
            ansp.push_back(j);
            anss.push_back(x);
        }
    }
    cout << "Case #" << test << ": ";
    cout << ansj.size() << endl;
    rep (i,ansj.size())
        cout << ansj[i] << " " << ansp[i] << " " << anss[i] << endl;
}

int main() {
    int i, t;
    cin >> t;
    rep (i,t) {
        solve(i+1);
    }
    return 0;
}
