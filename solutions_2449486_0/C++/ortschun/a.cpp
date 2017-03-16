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
const int MAXN = 105;
vector<long long> nums;
int T, N, M, grid[MAXN][MAXN];
string solve() {
	REP(i, N){
		REP(j, M){
			bool ok = false;
			REP(k, N){
				if(grid[i][j] < grid[k][j])
					break;
				if (k == N - 1) ok = true;
			}
			REP(k, M) {
				if (grid[i][j] < grid[i][k]) {
					break;
				}
				if (k == M - 1) ok = true;
			}
			if(!ok) {
				return "NO";
			}
		}
	}
	return "YES";
}
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.out", "w", stdout);
	cin>>T;
	REP(t, T){
		cin>>N>>M;
		REP(i, N){
			REP(j, M){
				cin>>grid[i][j];
			}
		}
		cout<<"Case #"<<(t + 1)<<": "<<solve()<<endl;
	}
	return 0;
}
