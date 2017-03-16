#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <ctime>
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define forn(a, n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define forall(a, all) for(typeof((all).begin()) a = (all).begin(); a != (all).end(); ++a)

#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define dforsn(a,s,n) for(int a = (n)-1; a>=(s); --a)
#define dforall(a, all) for(typeof((all).rbegin()) a = (all).rbegin(); a != (all).rend(); ++a)

#define contains(mask, bit) ((mask & (1LL<<bit)) != 0LL)

typedef long long tint;

int T, n;
list<int> adj[1004];

int vist[1004];
bool dfs(int i){
	if(vist[i]) return true;
	vist[i] = true;
	
	bool ret = false;
	forall(k, adj[i])
		ret |= dfs(*k);
	return ret;
}

int main()
{
#ifdef __YO__
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
#endif
	
	cin >> T;
	forn(t,T){
		cin >> n;
		forn(i,n){
			adj[i].clear();
			int m;
			cin >> m;
			forn(j, m){
				int tmp;
				cin >> tmp;
				adj[i].push_back(tmp-1);
			}
		}
		
		bool ret = false;
		forn(i,n){
			memset(vist,0,sizeof(vist));
			if(dfs(i)){
				ret = true;
				break;
			}
		}
		
		printf("Case #%i: ", t+1);
		if(ret) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
