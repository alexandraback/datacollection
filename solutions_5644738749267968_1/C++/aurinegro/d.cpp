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
#include <complex>
#include <cassert>
#include <bitset>
#include <cstring>
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
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair


typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<tint> vt;
typedef vector<vt> vvt;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int MAXN = 1000 + 10;

int n;
double a[MAXN], b[MAXN];

int go1() {
	int res = 0, l2 = 0, r2 = n-1;
	forn(l1,n) {
		if (a[l1] > b[l2]) {
			res++; l2++;
		}
		else {
			r2--;
		}
	}
	return res;
}

int go2(const vector<pair<double,int> > evt) {
	int res = n;
	int bal = 0;
	forn(i,si(evt)) {
		// cerr << evt[i].first << ' ' << evt[i].second << endl;
		if (evt[i].second == +1) bal++;
		else {
			if (bal) { res--; bal--; }
		}
	}
	return res;
}

int main() {
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);

        int ncas; cin >> ncas;
        forn(cas, ncas) {
        	cout << "Case #" << cas+1 << ": ";
        	cin >> n;
        	forn(i,n) cin >> a[i];
        	forn(i,n) cin >> b[i];

        	sort(a,a+n);
        	sort(b,b+n);

        	int resa = 0, resb;

        	vector<pair<double,int> > evt;
        	forn(i,n) evt.pb(mp(a[i], +1));
        	forn(j,n) evt.pb(mp(b[j], -1));
        	sort(all(evt));
    		// forn(i,si(evt)) cerr << evt[i].second << ' ';cerr << endl;	


        	cout << go1() << ' ' << go2(evt) << endl;
        }


        return 0;
}
