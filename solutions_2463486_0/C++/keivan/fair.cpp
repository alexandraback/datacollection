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

const int MAXL = 10 * 1000 * 1000 ;

vector <ll> pal ;

bool Pal(ll a) {
	ll x = a , y = 0 ;
	while (a) {
		y = y*10+a%10 ;
		a /= 10 ;
	}
	return x == y ;
}

int main() {
	for (ll i = 1 ; i <= MAXL ; ++i) {
		if (Pal(i) && Pal(i*i))
			pal.pb (i*i) ;
	}
	int T ;
	cin >> T ;
	FOR (l,1,T+1) {
		int A , B ;
		cin >> A >> B ;
		cout << "Case #" << l << ": " << upper_bound(all(pal),B)-lower_bound(all(pal),A) << endl ;
	}
	return 0 ;
}
