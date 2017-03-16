#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <complex>
#include <cassert>
#include <bitset>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cout << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair

typedef long long int tint;
typedef long double tipo;

#define MAXN 1024
#define EPS 1.0E-8
#define EPS2 1.0E-14


int T,n,s[MAXN];
tipo x;

bool check(int i, double p) {
	tipo mypoints = s[i] + x*p;	
	tipo sum = 0.0;
	forn(j,n) if ((mypoints-s[j])/x > 0.0) sum += (mypoints-s[j])/x;
	if (sum<1.0-EPS2) return false; 
	else return true;
}

void init() {
	x=0.0;	
	
}


int main () {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	cin >> T;
	forn(rep,T) {
		init();
		cin >> n;
		forn(i,n) {
			cin >> s[i];
			x+= s[i];
		}	
		
		cout << "Case #" << rep+1 << ":";
		
		forn(i,n) {
			tipo start = 0.0, end = 1.0, mid = (end+start)*0.5;	
			while(end-start > EPS) {
				mid = (end+start)*0.5;
				if (check(i,mid)) { // vive
					end = mid;
				} else start = mid;
			}
			printf(" %.7lf",(double) (100.0*mid));
		}	
		
		cout << endl;		
	}

	return 0;
}
