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

int T ;
int a[4][4] ;

int main() {
	cin >> T ;
	FOR (l,1,T+1) {
		pii p = pii(-1,-1) ;
		int num = 0 ;
		FOR (i,0,4) {
			FOR (j,0,4) {
				char ch ;
				cin >> ch ;
				a[i][j] = ((ch=='.')?-1:((ch == 'X')?0:((ch == 'O')?1:2))) ;
				if (ch == 'T')
					p = pii(i,j) ;
				num += (ch != '.') ;
			}
		}
		bool win[2] = {false,false} ;
		FOR (S,0,2) {
			if (p.X >= 0) {
				a[p.X][p.Y] = S ;
			}
			FOR (k,0,2) {
				FOR (i,0,4) {
					int s = 0 ;
					FOR (j,0,4)
						s += (a[i][j] == k) ;
					if (s == 4)
						win[k] = true ;
				}
				FOR (F,0,4) {
					FOR (p,-1,2) {
						int s = 0 ;
						int d = F ;
						FOR (i,0,4) {
							if (d >= 0 && d < 4)
								s += (a[i][d] == k) ;
							d += p ;
						}
						if (s == 4)
							win[k] = true ;
					}
				}
			}
		}
		cout << "Case #" << l << ": " ;
		if (win[0])
			cout << "X won" ;
		else if (win[1])
			cout << "O won" ;
		else if (num == 16)
			cout << "Draw" ;
		else
			cout << "Game has not completed" ;
		cout << endl ;
	}
	return 0 ;
}
