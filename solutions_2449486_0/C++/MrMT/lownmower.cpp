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

int n, m;
int lawn[200][200];
int grass[200][200];

int main() {

	int casos;
	cin >> casos;
	forn(t, 0, casos) {
		cin >> n >> m;
		forn(i, 0, n) forn(j, 0, m) cin >> lawn[i][j];
		forn(i, 0, n) forn(j, 0, m) grass[i][j] = 100;

		forn(i, 0, n) {
			int mx = 0;
			forn(j, 0, m) mx = max(mx, lawn[i][j]);

			forn(j, 0, m) grass[i][j] = min(grass[i][j], mx);
		}

		forn(j, 0, m) {
			int mx = 0;
			forn(i, 0, n) mx = max(mx, lawn[i][j]);

			forn(i, 0, n) grass[i][j] = min(grass[i][j], mx);
		}
		
		bool eq = true;
		forn(i, 0, n)forn(j, 0, m) eq= eq && (grass[i][j] == lawn[i][j]);
	
	
		cout << "Case #" << t+1 << ": ";
		if(eq) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}


