
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)


int last[2000111];
int prev[2000111];
int nlast[2000111];
int vals[2000111];
int dp[1<<20];
int main() {
	int tc;
	cin >> tc;
	FOR(tcc,1,tc+1){
		memset(last,-1,sizeof(last));
		memset(nlast,-1,sizeof(nlast));
		int N;
		cin >> N;
		int maxi = 1;
		FOR(ii,0,N){
			int val;
			cin >> val;
			if(last[val] == -1){
				nlast[val] = val;
				prev[val] = 0;
			}
			FOR(i,0,maxi)if(last[i] != -1){
				if(nlast[i + val] == -1){
					nlast[i + val] = val;
					prev[i + val] = i;
				}
				if(nlast[abs(i-val)] == -1){
					nlast[abs(i-val)] = val;
					prev[abs(i - val)] = i;
				}
			}
			maxi += val;
			FOR(i,0,maxi)last[i] = nlast[i];
		}
		cout << "Case #" << tcc << ":\n";
		if(last[0] == -1)cout << "Impossible\n";
		else {
			N = 0;
			int cur = 0;
			do{
				vals[N++] = last[cur];
				cur = prev[cur];
			}while(cur);
			dp[0] = 0;
			FOR(i,0,N)dp[1<<i] = vals[i];
			FOR(i,1,1<<N){
				int part = i & (-i);
				dp[i] = dp[i^part] + dp[part];
			}
			if(dp[(1<<N)-1]&1)cout << "FAIL\n";
			FOR(mask,0,1<<N){
				if(dp[mask] * 2 == dp[(1<<N)-1]){
					bool first = true;
					FOR(i,0,N)if(mask & (1<<i)){
						if(first)first = false;
						else cout << " ";
						cout << vals[i];
					}
					cout << endl;
					first = true;
					FOR(i,0,N)if((mask & (1<<i))==0){
						if(first)first = false;
						else cout << " ";
						cout << vals[i];
					}
					cout << endl;
					break;
				}
			}
		}
	}
	return 0;
}
