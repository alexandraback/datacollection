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
const int MOD = 1000000007;
const int MAXN = 5;
int T, N, M, dx[] = {1, 0, 1, -1}, dy[] = {0, 1, 1, 1};
string xwin = "XXXX", xwin2 = "TXXX";
string owin = "OOOO", owin2 = "OOOT";
char grid[MAXN][MAXN];
string solve() {
	REP(i, 4){
		REP(j, 4){
			REP(k, 4){
				string str = "";
				for(int l = 0; l < 4; l ++){
					int nx = i + l * dx[k], ny = j + l * dy[k];
					if(nx >= 4 || ny >= 4 || nx < 0 || ny < 0) break;
					str += grid[nx][ny]; 
				}
				if(SIZE(str) != 4) continue;
				sort(ALL(str));
				if(xwin == str || xwin2 == str){
					return "X won";
				}
				if(owin == str || owin2 == str){
					return "O won";
				}
			}
		}
	}
	REP(i, 4){
		REP(j, 4){
			if(grid[i][j] == '.') {
				return"Game has not completed";
			}
		}
	}
	return "Draw";
}
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output.out", "w", stdout);
	cin>>T;
	REP(t, T){
		REP(i, 4){
			REP(j, 4){
				cin>>grid[i][j];
			}
		}
		cout<<"Case #"<<(t + 1)<<": "<<solve()<<endl;
	}
	return 0;
}
