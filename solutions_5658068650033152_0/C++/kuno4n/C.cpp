#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf
#define gout case_number++, printf("Case #%d: ",case_number), cout

int n, m, k;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int bo[20][20];

bool valid(int a, int b){
    if(a < 0 || a >= n || b < 0 || b >= m || bo[a][b] != 0) return false;
    return true;
}

void bfs(int a, int b){
    if(!valid(a, b)) return;
    bo[a][b] = 2;
    queue<int> qx;
    queue<int> qy;
    qx.push(a);
    qy.push(b);
    while(SZ(qx)) {
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();
        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(valid(nx, ny)){
                bo[nx][ny] = 2;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
}

void init() {
}

void input() {
    cin >> n >> m >> k;
}

void solve() {
    if(n <= 2 || m <= 2){
        gout << k << endl;
        return;
    }
    int res = n * m;
    
    REP(msk, (1<<(n*m))){
//        OUT(msk);
        REP(i, n) REP(j, m) bo[i][j] = 0;
        REP(i, n*m) if(msk & (1<<i)) bo[i/m][i%m] = 1;
        REP(i, n) bfs(i, 0), bfs(i, m-1);
        REP(i, m) bfs(0, i), bfs(n-1, i);
        int cnt = 0;
        int used = 0;
        REP(i, n) REP(j, m){
            if(bo[i][j] != 2) cnt++;
            if(bo[i][j] == 1) used++;
        }
        if(cnt >= k) chmin(res, used);
//        if(cnt >= k){
//            REP(i, n){
//                REP(j, m) cout << bo[i][j];
//                cout << endl;
//            }
//            cout << endl;
//        }
    }

    gout << res << endl;
}

int main() {
	init();
	int number_of_test_cases;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases){
		input();
		solve();
	}
	return 0;
}
