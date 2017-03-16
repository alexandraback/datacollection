#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <set> 
#include <sstream>
#include <fstream>
#include <utility>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define REP(i,a) for(int i=0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define SIZE(c) (int)c.size()
#define ALL(c) (c).begin(),(c).end() 
typedef pair<int, int> PII;
const int INF = 1000000000;
const int MAXN = 51;
int T, R, C, M, cx, cy;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
char board[MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN*MAXN];
bool dp[MAXN][MAXN][MAXN*MAXN];
bool valid(int x, int y){
	return x >= 0 && y >= 0 && x < R && y < C;
}
bool noMineNeigh(int x, int y){
	bool ok = true;
	for(int k = 0; k < 8; k ++){
		int nx = x + dx[k], ny = y + dy[k];
		if (valid(nx, ny) && board[nx][ny] == '*'){
			ok = false;
		}
	}
	return ok;
}
bool can(int idx, int last, int K){
	if (K < 0) return false;
	if(idx == R){
		return K == 0;
	}
	if(vis[idx][last][K]) return dp[idx][last][K];
	vis[idx][last][K] = true;
	if(idx == R - 1){
		return dp[idx][last][K] = can(idx + 1, last, K - last);
	}
	bool ok = false;
	for (int i = last; i <= C; i ++){
		if (i == 1) continue;
		ok |= can(idx + 1, i, K - i);
	}
	return dp[idx][last][K] = ok;
}
int main() {
	freopen("a.in", "r", stdin);
	cin>>T;
	REP(t, T){
		cin>>R>>C>>M;
		cout<<"Case #"<<(t + 1)<<":"<<endl;
		if (R == 1 || C == 1){
			if (M == 0){
				REP(i, R){
					REP(j, C){
						if (i == 0 && j == 0) {
							cout<<'c';
						} else {
							cout<<'.';
						}
					}
					cout<<endl;
				}
			} else if ((R * C - M) < 2) {
				cout<<"Impossible"<<endl;
			} else {
				int spaceCount = R * C - M;
				REP(i, R){
					REP(j, C){
						if (i == 0 && j == 0){
							cout<<'c';
							spaceCount --;
						} else if(spaceCount > 0){
							cout<<".";
							spaceCount--;
						} else {
							cout<<"*";
						}
					}
				}
			}
		}
		int K = R * C - M;
		memset(vis, 0, sizeof vis);
		bool ret = can(0, 0, K);
		if (!ret) {
			cout<<"Impossible"<<endl;
		} else {
			int r = 0, last = 2, left = K, space = 0;
			while (r < R){
				for (int i = last; i <= C; i ++){
					if (can(r + 1, last, left - i)) {
						space = i;
						left = left - i;
						last = i;
						i = C + 1;
					}
				}
				r ++;
				for (int i = 0; i < space; i ++){
					board[r][i] = '.';
				}
				for(int i = 0; i < C - space; i ++){
					board[r][space + i] = '*';
				}
			}
			REP(i, R){
				REP(j, C){
					if (board[i][j] == '.' && noMineNeigh(i, j)){
						board[i][j] = 'c';
						i = R + 1; j = C + 1;
					}
				}
			}
			REP(i, R){
				REP(j, C){
					cout<<board[i][j];
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
