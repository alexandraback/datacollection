#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i,j,k) for(int i=j;i<(int)(k);++i)
#define foreach(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 99999999;
const double EPS = 1e-9;

int T,N;
bool ans;
vvi M;
set<int> s;

void dfs(int v)
{
	if(s.find(v)!=s.end()) ans=true;
	else s.insert(v);
	if(ans) return;
	rep(i,N)if(M[v][i]) dfs(i);
}

int main()
{
	cin >> T;
	rep(t,T){
		ans = false;
		cin >> N;
		M.resize(N,(vi(N,0)));
		rep(i,N){
			int n;
			cin >> n;
			rep(j,n){
				int in;
				cin >> in;
				M[i][in-1]=1;
			}
		}
//		rep(i,N)rep(j,N) printf("%d%c",M[i][j],j!=N-1?' ':'\n');
		rep(i,N){
			if(ans) break;
			dfs(i);
			s.clear();
		}
		printf("Case #%d: %s\n",t+1,ans?"Yes":"No");
		M.clear();
	}
	return 0;
}
