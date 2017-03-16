#include <cmath>
#include <queue>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>

using namespace std;

#define sz(X) ((int)X.size())
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define fr(i,a,b) for(int i=a; i<=b; i++)
#define it(it) __typeof((it)->begin())
#define foreach(v) for(IT(v) it=(v)->begin(); it!=(v)->end(); it++)
#define all(x) (x).begin(),x.end()
#define pb(x) push_back(x)
#define VI vector<int> 
#define VVI vector<vector<int> >
#define VS vector<string>
typedef long long ll;

bool go(int node, int dest, vector<bool>& visited, VVI const& memo)
{
	if (node == dest && visited[node]) return true;
	else if (node == dest) { visited[node]=true; return false; }
	if (visited[node]) return false;
	visited[node]=true;
	rep(i,memo[node].size()) {
		bool found=go(memo[node][i],dest,visited,memo);
		if (found) return true;
	}

	return false;
}
int main()
{
	
	//freopen("data.in","r",stdin);
    int T, N, M;
    cin >> T;
    rep(zz,T) {
		int ret=0;
		cin >> N;
		VVI v(N);
		rep(i,N) {
			cin >> M;
			rep(j,M) {
				int tmp;
				cin >> tmp;
				v[i].push_back(tmp-1);				
			}

		}
		bool found=false;
		rep(i,N) {
			rep(j,N) {
				vector<bool> visited(N);				
				found=go(i,j,visited,v);
				if (found) goto done;
				
			}
		}
		done:;
		if (found)
			printf("Case #%d: Yes\n", zz+1);
		else
			printf("Case #%d: No\n", zz+1);
    }
    return 0;
}
