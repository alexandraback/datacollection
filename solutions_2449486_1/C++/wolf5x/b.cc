#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP(x,y) make_pair((x),(y))
#define FI(x) ((x).first)
#define SE(x) ((x).second)
#define SZ(x) ((x).size())
#define LEN(x) ((x).length())

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int T, N, M;
vector<vector<int> > A;

bool solve(vector<vector<int> > &b) {
    if(b.size() == 0) return true;
    int n = b.size(), m = b[0].size();
    //REP(i, n) REP(j, m) cout << b[i][j] << (j<m-1?" ":"\n"); cout << "\n";
    if(n <= 1 || m <= 1) return true;
    int lo = b[0][m-1], lr = 0, lc = m-1;
    FORD(j, m, 0) REP(i, n) if(b[i][j] < lo) 
        lo = b[i][j], lr = i, lc = j;
    bool f = true;
    REP(i, n) f = f && b[i][lc] == lo;
    if(f) {
        REP(i, n) b[i].erase(b[i].begin()+lc);
        return solve(b);
    }
    f = true;
    REP(j, m) f = f && b[lr][j] == lo;
    if(f) {
        b.erase(b.begin() + lr);
        return solve(b);
    }
    return false;
}

int main() {
    cin >> T;
    FOR(cas, 1, T+1) {
        cin >> N >> M;
        A.resize(N);
        REP(i, N) {
            A[i].resize(M);
            REP(j, M) scanf("%d", &A[i][j]);
        }
        cout << "Case #" << cas << ": "
            << (solve(A) ? "YES" : "NO")
            << endl;
    }
	return 0;
}

