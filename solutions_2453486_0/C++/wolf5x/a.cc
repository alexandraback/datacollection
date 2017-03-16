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

int T;
vector<string> b(4);
int dp[2][4][4][4], win[2];
int dr[] = {0,-1,-1,-1};
int dc[] = {-1,0,-1,1};
char id[128];

int main() {
    cin >> T;
    FOR(cas, 1, T+1) {
        REP(i, 4) cin >> b[i];
        CLR(dp); CLR(win);
        int cnt = 0;
        REP(i, 4) REP(j, 4) {
            if(b[i][j] == '.') b[i][j] = 0;
            else if(b[i][j] == 'X') b[i][j] = 1;
            else if(b[i][j] == 'O') b[i][j] = 2;
            else b[i][j] = 3;
            if(b[i][j]) cnt++;
            REP(p, 2) if(b[i][j]&(1<<p)) {
                REP(k, 4) {
                    dp[p][i][j][k] = 1;
                    int tr = i+dr[k], tc = j+dc[k];
                    if(tr >= 0 && tc >= 0 && tr < 4 && tc < 4) {
                        dp[p][i][j][k] += dp[p][tr][tc][k];
                        if(dp[p][i][j][k] >= 4) win[p] = 1;
                    }
                }
            }
        }
        cout << "Case #" << cas << ": ";
        cout << (win[0] ? "X won" 
                : win[1] ? "O won"
                : cnt==16 ? "Draw" 
                : "Game has not completed") 
            << endl;
    }
    return 0;
}

