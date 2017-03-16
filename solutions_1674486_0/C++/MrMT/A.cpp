#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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

using namespace std;

#define forn(i, a, b) for(int i=(a);i<int(b);i++)
#define PB push_back
#define MP(X,Y) make_pair(X,Y)
#define SZ(X) ((int)(X.size()))
#define ALL(x)   (x).begin(),(x).end()
#define foreach(it, c)  for(typeof((c).begin()) it = (c).begin();it!=(c).end();++it)
#define F first
#define S second
#define CLEAR(A, V) memset(A, V, sizeof(A))

typedef  long long   ll;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef vector<II> VII;

template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
template<class T> inline T gcd(T a, T b){ return b?gcd(b, a%b):a;}
const double EPS = 1e-9;
const double PI = acos(-1.0);

int n;
vector<int> edges[1010], tr[1010];
bool visited[1010];

void dfs(int node) {
	visited[node] = true;
	forn(i, 0, SZ(edges[node])) if(!visited[edges[node][i]])
		dfs(edges[node][i]);
}

int main(void) {
	
	int casos;
	cin >> casos;
	forn(t, 0, casos) {
	
		forn(i, 0, 1010) edges[i].clear(), tr[i].clear();
		memset(visited, 0, sizeof(visited));

		cin >> n;
		int m, x;
		forn(i, 0, n) {
			cin >> m;
			forn(j, 0, m) {	
				cin >> x;
				x--;
				edges[i].PB(x);
				tr[x].PB(i);
			}
		}

		bool valid = false;
		forn(i, 0, n) {
			if(valid) break;

			memset(visited, 0, sizeof(visited));
			dfs(i);

			forn(j, 0, n) if(i != j && SZ(tr[j]) >= 2) {
				if(valid) break;
				int cnt = 0;
				forn(k, 0, SZ(tr[j])) {
					if(cnt >= 2) break;
					cnt += visited[tr[j][k]];
				}
				if(cnt >= 2) valid = true;
			}
		}
		if(valid) cout << "Case #" << t+1 << ": Yes" << endl;
		else cout << "Case #" << t+1 << ": No" << endl;

	}

	return 0;
}
