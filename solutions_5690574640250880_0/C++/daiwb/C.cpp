#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

#define MAXN 25
int cnt;
int R, C, M;
bool found;

int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int mat[5][5], num[5][5], vv[5][5];

void doit(int* a,int n){
    memset(mat, 0, sizeof(mat));
    memset(num, 0, sizeof(num));
    REP(i,n) {
        int x = (a[i] - 1) / C;
        int y = (a[i] - 1) % C;
        mat[x][y] = 1;
        REP(j,8) {
            int tx = x + dir[j][0];
            int ty = y + dir[j][1];
            if (tx < 0 || tx >= R || ty < 0 || ty >= C) continue;
            ++num[tx][ty];
        }
    }
    int sx = -1, sy = -1;
    REP(i,R) {
        REP(j,C) {
            if (mat[i][j] == 0 && num[i][j] == 0) {
                sx = i, sy = j;
                break;
            }
        }
        if (sx != -1) break;
    }
    if (sx == -1) return;

    memset(vv, 0, sizeof(vv));
    int sum = 1;
    vv[sx][sy] = 1;
    deque<pair<int, int> > que;
    que.push_back(make_pair(sx, sy));
    while (!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop_front();
        REP(i,8) {
            int tx = cx + dir[i][0];
            int ty = cy + dir[i][1];
            if (tx < 0 || tx >= R || ty < 0 || ty >= C) continue;
            if (mat[tx][ty] == 1) continue;
            if (vv[tx][ty] == 1) continue;
            vv[tx][ty] = 1;
            ++sum;
            if (num[tx][ty] == 0) que.push_back(make_pair(tx, ty));
        }
    }
    if (sum + M == R * C) {
        found = true;
        REP(i,R) {
            REP(j,C) {
                if (sx == i && sy == j) cout << "c";
                else if (mat[i][j] == 1) cout << "*";
                else cout << ".";
            }
            cout << endl;
        }
    }
}

void _gen_comb(int* a,int s,int e,int m,int& cnt,int* temp){
    if (found) return;
	if (!m) {
		doit(temp,cnt);
    } else {
        FOR(i,s,e-m+1) {
			temp[cnt++]=a[i];
			_gen_comb(a,i+1,e,m-1,cnt,temp);
			cnt--;
		}
    }
}

void gen_comb(int n,int m){
	int a[MAXN],temp[MAXN],cnt=0;
	REP(i,n) a[i]=i+1;
	_gen_comb(a,0,n-1,m,cnt,temp);
}

void run() {
    found = false;
    cin >> R >> C >> M;
    if (R * C == M + 1) {
        REP(i,R) {
            REP(j,C) {
                if (i + j == 0) cout << "c";
                else cout << "*";
            }
            cout << endl;
        }
        return;
    }
    gen_comb(R * C, M);
    if (!found) {
        cout << "Impossible" << endl;
    }
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ":" << endl;
        run();
    }
    return 0;
}
