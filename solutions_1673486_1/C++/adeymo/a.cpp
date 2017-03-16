#include <vector>
#include <queue>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

/* tipos */
typedef pair<int,int> pint;
typedef long long tint;
typedef unsigned int mint;
typedef unsigned long long mtint;

typedef vector<int> vint;
typedef vector<vint> vvint;

typedef long double tdbl;

/* "funciones" */
#define forn(i,n) for(int ___n=n, i=0;i<___n;++i)
#define dforn(i,n) for(int i=(n)-1;i>=0;--i)
#define forsn(i,s,n) for(int ___n=n, i=s;i<___n;++i)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define forall(it,X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define dforall(it,X) for(typeof((X).rbegin()) it = (X).rbegin(); it != (X).rend(); ++it)
#define all(X) (X).begin(), (X).end()
#define esta(e, c) (c.find(e) != c.end())
#define DBG(a) cerr << #a << " = " << a << endl;

template<class T> string itos(const T&x) { ostringstream o; o<<x; return o.str(); }


int main() {
	int tt;
	cin >> tt;
	forn(_t, tt) {
		int a, b;
		cin >> a >> b;
		vector<tdbl> pa; pa.resize(a);
		vector<tdbl> pp; pp.resize(a+1);
		pp[0] = 1.0;
		
		forn(i,a) { cin >> pa[i]; pp[i+1] = pp[i] * pa[i]; }

		/* Caso 3: giveup */
		tdbl res = b+2;

		/* Caso 2: backspace */
		forn(i, a+1) {
			tdbl rres = pp[a-i] * (i+b-(a-i)+1) + (1.0L-pp[a-i]) * ((i+b-(a-i)+1) + b+1);
			if (rres < res) res = rres;
			// DBG(rres)
		}

		printf("Case #%d: %.8lf\n", _t+1, (double)res);
	}
	return 0;
}

