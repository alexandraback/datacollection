#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define REPP(i,s,e) for(int i=s; i<=e; i++)
#define PB(a) push_back(a)
#define MP(i,s) make_pair(i,s)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()
#define PRT(a) cerr << #a << " = " << (a) << endl
#define PRT2(a,b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << endl
#define PRT3(a,b,c) cerr << (a) << ", " << (b) << ", " << (c) << endl

typedef long long lint;
typedef pair<lint,lint> pll;
typedef pair<int,int> pii;

int M, R, C;
int data[55][55];
int num[55][55];
bool open[55][55];

int dr[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int dc[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

bool click(int r, int c) {
    memset(open, 0, sizeof(open));
    memset(num, 0, sizeof(num));
    REP(i,R) {
        REP(j,C) {
            int cnt = 0;
            REP(k,8) {
                int ii = i + dr[k];
                int jj = j + dc[k];
                if(ii >= 0 && jj >= 0 && ii < R && jj < C) {
                    if(data[ii][jj]) cnt++;
                }
            }
            num[i][j] = cnt;
        }
    }

    queue<pii> que;
    que.push(pii(r, c));
    open[r][c] = true;
    while(!que.empty()) {
        int pr = que.front().first;
        int pc = que.front().second;
        que.pop();

        if(num[pr][pc] == 0) {
            REP(k,8) {
                int rr = pr + dr[k];
                int cc = pc + dc[k];
                if(rr >= 0 && cc >= 0 && rr < R && cc < C) {
                    if(!open[rr][cc]) {
                        open[rr][cc] = true;
                        que.push(pii(rr, cc));
                    }
                }
            }
        }
    }

    REP(i,R) {
        REP(j,C) {
            if(!data[i][j] && !open[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool check(int& cr, int& cc) {
    REP(i,R) {
        REP(j,C) {
            if(data[i][j]) continue;

            if(click(i, j)) {
                cr = i;
                cc = j;
                return true;
            }
        }
    }
    return false;
}

int bitCount(lint a) {
    int ret = 0;
    while(a != 0) {
        ret += (a & 0x01);
        a >>= 1;
    }
    return ret;
}

void solve() {
    int cr, cc;
    int n = R * C;
    for(lint mask=0; mask<(1ll<<n); mask++) {
        if(bitCount(mask) != M) continue;

        memset(data, 0, sizeof(data));
        REP(i,R) {
            REP(j,C) {
                int idx = i * C + j;
                if(mask & (1ll << idx)) {
                    data[i][j] = 1;
                }
            }
        }
        
        cr = cc = -1;
        if(check(cr, cc)) {
            REP(i,R) {
                REP(j,C) {
                    if(i == cr && j == cc) {
                        printf("c");                        
                    } else {
                        printf("%c", ".*"[data[i][j]]);
                    }
                }
                printf("\n");
            }
            return;
        }
    }
    printf("Impossible\n");
}

void coding() {
    int T;
    while(cin>>T) {
        REP(t,T) {
            printf("Case #%d:\n", t+1);
            cin>>R>>C>>M;
            solve();
        }
    }
}

// #define _LOCAL_TEST

int main() {
#ifdef _LOCAL_TEST
	clock_t startTime = clock();
	freopen("c.in", "r", stdin);
#endif
	coding();

#ifdef _LOCAL_TEST
	clock_t elapsedTime = clock() - startTime;
	cout << endl;
	cout << (elapsedTime / 1000.0) << " sec elapsed." << endl;
	cout << "This is local test" << endl;
	cout << "Do not forget to comment out _LOCAL_TEST" << endl << endl;
#endif
}
