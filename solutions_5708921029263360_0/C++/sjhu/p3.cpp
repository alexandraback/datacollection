#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
 
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
 
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long
#define SZ size()
#define read(filename) freopen(filename, "r", stdin)
#define write(filename) freopen(filename, "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define INF 1<<29
#define mod(a) (a>0?a:-a)
#define pf printf
 
using namespace std;
 
int j,p,s,k;

int next(int mode, int num) {
	if (mode == 1) {
		if (num == j) {
			return 1;
		} else {
			return (++num);
		}
	} else if (mode == 2) {
		if (num == p) {
			return 1;
		} else {
			return (++num);
		}
	} else {
		if (num == s) {
			return 1;
		} else {
			return (++num);
		}
	}
}

int main()
{
    int T;
    getint(T); 

    loop(o, T) {
    	getint(j);
    	getint(p);
    	getint(s);
    	getint(k);

    	if (s < k) {
    		k = s;
    	}

		cout << "Case #" << o+1 << ": " << j*p*k << endl;

		int a,b,c, clast, cl;

		// a = next(1, a);
		// b = next(2, b);
		// c = next(3, c);

		a = 1;
		b = 1;
		c = 1;
		clast = 1;
		cl = 1;

		loop(x, k) {
			loop(y, j) {
				loop(z, p) {
					cout << a << " " << b << " " << c << endl;
					b = next(2, b);
					c = next(3, c);
				}
				a = next(1, a);
				cl = next(3, cl);
				c = cl;
			}
			clast = next(3, clast);
			c = clast;
			cl = clast;
		}

    }
    return 0;
}