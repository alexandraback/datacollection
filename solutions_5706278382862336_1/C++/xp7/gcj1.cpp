/* Paras Narang 
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <deque>
#include <bitset>
#include <cmath>
#include <set>
#include <sstream>

using namespace std;

#define oo 0x7F7F7F7F
#define LET(x,a)     __typeof(a) x(a)
#define EACH(it,v)   for(LET(it,v.begin());it!=v.end();++it)
#define REP(i,n)     for(__typeof(n) i(0); i<n; i++)
#define FOR(i,j,n)   for(__typeof(n) i(j); i<n; i++)
#define ALL(x)       (x).begin(), (x).end()
#define gint(t)      scanf("%d", &t);
#define pint(t)      printf("%d\n", t);
#define pb           push_back
#define mp           make_pair

typedef long long int   ll;
typedef unsigned long long int ull;
typedef unsigned int    uint;
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<vi>      vii;
typedef vector<pii>     vpii;

ll gcd(ll a, ll b) {
    ll x;
    while(b) {
		x = a%b;
		a = b;
		b = x;
    }
    return a;
}

int main() {
    int t; gint(t);
    REP(ti, t) {
        int res = 0;
        long long int a,b;
        scanf("%lld/%lld",&a,&b);
        ll myGCD = gcd(a,b);
        a /= myGCD;
        b /= myGCD;
        long double c = 0.0;
        c = (long double)a/(long double)b;
        // cout << " c " << c << endl;
        if( (b & (b-1)) == 0){
        	while(c<1){
        		c*=2;
        		res++;
        		// cout << " c " << c << " - " << res << endl;
        	}
        	printf("Case #%d: %d\n", ti+1, res);
        }
        else{
        	printf("Case #%d: impossible\n", ti+1);
        }
    }
    return 0;
}