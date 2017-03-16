#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define F first
#define S second
#define PB push_back
#define PF push front
#define MP make_pair
#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define VAR(v,n) __typeof(n) v=(n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define MOD(x, n) ((x)%(n)+(n))%(n)
#define SZ(x) (int((x).size()))
#define ALL(x) ((x).begin()),((x).end())
#define SORT(v) sort((v).begin(),(v).end())
#define REV(v) reverse((v).begin(),(v).end())
#define UNIQUE(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
LL GCD( LL a , LL b ) { while( b ) b ^= a ^= b ^= a %= b ; return a ; }
LL LCM( LL a , LL b ) { return a * ( b / GCD( a , b ) ) ; }

typedef vector<int>    VI;
typedef vector<VI>     VVI;
typedef vector<LL>     VLL;
typedef vector<bool>   VB;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII>    VPII;
typedef pair<LL, LL>   PLL;
typedef vector<PLL>    VPLL;

const double EPS = 10e-9;
const LL INF = (1LL << 30);

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

#endif
    int T;
    cin >> T;

    REP(t, T) {
        string brd[4];
        REP(j, 4) {
            cin >> brd[j];
        }
        bool won[] = {false, false};
        string msg[] = {"O won", "X won", "Draw", "Game has not completed"};
        {
            int cnt[] = {0, 0};
            REP(i, 4) {
                memset(cnt, 0, sizeof(cnt));
                REP(j, 4) {
                    if(brd[i][j] == 'O')
                        cnt[0]++;
                    else if(brd[i][j] == 'X')
                        cnt[1]++;
                    else if(brd[i][j] == 'T'){
                        cnt[0]++;
                        cnt[1]++;
                    }
                }
                if(cnt[0] == 4) {
                    won[0] = true;
                }
                else if(cnt[1] == 4) {
                    won[1] = true;
                }
            }
        }

        // cols
        {
            int cnt[] = {0, 0};
            REP(j, 4) {
                memset(cnt, 0, sizeof(cnt));
                REP(i, 4) {
                    if(brd[i][j] == 'O')
                        cnt[0]++;
                    else if(brd[i][j] == 'X')
                        cnt[1]++;
                    else if(brd[i][j] == 'T'){
                        cnt[0]++;
                        cnt[1]++;
                    }
                }
                if(cnt[0] == 4) {
                    won[0] = true;
                }
                else if(cnt[1] == 4) {
                    won[1] = true;
                }
            }
        }

        // diags
        {
            int cnt[] = {0, 0};
            REP(i, 4) {
                if(brd[i][i] == 'O')
                    cnt[0]++;
                else if(brd[i][i] == 'X')
                    cnt[1]++;
                else if(brd[i][i] == 'T'){
                    cnt[0]++;
                    cnt[1]++;
                }
            }
            if(cnt[0] == 4) {
                won[0] = true;
            }
            else if(cnt[1] == 4) {
                won[1] = true;
            }
        }

        {
            int cnt[] = {0, 0};
            REP(i, 4) {
                if(brd[i][3-i] == 'O')
                    cnt[0]++;
                else if(brd[i][3-i] == 'X')
                    cnt[1]++;
                else if(brd[i][3-i] == 'T'){
                    cnt[0]++;
                    cnt[1]++;
                }
            }
            if(cnt[0] == 4) {
                won[0] = true;
            }
            else if(cnt[1] == 4) {
                won[1] = true;
            }
        }

        bool full = true;
        REP(i, 4) {
            REP(j, 4) {
                if(brd[i][j] == '.')
                    full = false;
            }
        }

        if(won[0] && won[1]) {
            printf("Case #%d: %s\n", (t+1), msg[1].c_str());
        }
        if(won[0]) {
            printf("Case #%d: %s\n", (t+1), msg[0].c_str());
        }
        else if(won[1]) {
            printf("Case #%d: %s\n", (t+1), msg[1].c_str());
        } else {
            if(full)
                printf("Case #%d: %s\n", (t+1), msg[2].c_str());
            else
                printf("Case #%d: %s\n", (t+1), msg[3].c_str());
        }
    }

    return 0;
}

