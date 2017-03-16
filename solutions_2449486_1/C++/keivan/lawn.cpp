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
#include <cstring>
 
using namespace std;
 
#define FOREACH(i, c) for(__typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for(__typeof(n) i = (a); i<(n); ++i)
#define REP(i, n, a) for(__typeof(n) i = (n); i>=(a); --i)
#define error(n) cout << #n << " = " << n << endl
#define all(c) c.begin(), c.end()
#define pb push_back
#define po pop_back
#define Size(n) ((int)(n).size())
#define X first
#define Y second
#define scanf _ = scanf
// #define X real()
// #define Y imag()

typedef long long   ll ;
typedef long double ld ;
typedef pair<int,int> pii ;

const int MAXN = 111 ;

int T ;
int n , m ;
int a[MAXN][MAXN] ;
int b[MAXN] , c[MAXN] ;

int main() {
	cin >> T ;
	FOR (l,1,T+1) {
		memset (a,0,sizeof(a)) ;
		memset (b,0,sizeof(b)) ;
		memset (c,0,sizeof(c)) ;
		//
		cin >> n >> m ;
		FOR (i,0,n) FOR (j,0,m) {cin >> a[i][j] ; b[i] = max(b[i],a[i][j]) , c[j] = max(c[j] , a[i][j]) ;}
		bool flag = true ;
		FOR (i,0,n) FOR (j,0,m) if (a[i][j] < b[i] && a[i][j] < c[j]) flag = false ;
		cout << "Case #" << l << ": " << ((flag)?"YES":"NO") << endl ;
	}
	return 0 ;
}
