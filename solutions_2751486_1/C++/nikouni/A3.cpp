#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
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

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef set<int> se;
typedef long long int tint;
typedef pair<tint,tint> pii;

#define forsn(i,s,n) for(tint i = (tint)(s); i<((tint)n); i++)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i>=((tint)s); i--)
#define forn(i,n) for(tint i=0;i<(tint)(n);i++)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define rall(c) (c).rbegin(), (c).rend()
#define all(c) (c).begin(), (c).end()
#define D(a) << #a << "=" << a << " "


#define si(a) tint((a).size())
#define pb push_back
#define mp make_pair
#define MAXN 1000005

int main () {
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	
    tint cases;
    cin >> cases;
    string s; tint n;
    forn(tt,cases) {		
		vector<pii> inter;
		
		cin >> s;
		cin >> n;	
		
		tint cont = 0;
		tint last = 0;
		forn(i,si(s)) {						
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				if (cont >=n) {
					inter.pb(mp(last,i-1));
				}
				cont = 0;
				last = i+1;				
			}
			else {				
				cont++;				
			}			 
		}
		
		if (cont >=n) inter.pb(mp(last,si(s)-1));
		
		
		vi M(si(s),-1);
		forn(i,si(inter)) 
			forsn(j,inter[i].first,inter[i].second+1)
				M[j] = i;
		
				
		dforsn(i,0,si(s)-1) 
			if (M[i] == -1) M[i] = M[i+1];	
		
		tint res = 0;
		tint pos;
		forn(i,si(s)) {
			if (M[i] != -1) {
				if (i >= inter[M[i]].first) {
					pos = i + n -1;
					if (pos > inter[M[i]].second) {
						if (M[i] == si(inter) -1) continue;
						pos = inter[M[i] + 1].first + n - 1;
					}
				} //dentro
				else {
					pos = inter[M[i]].first + n - 1;
				} //fuera
				res += si(s) - pos;
				
			}
		}
		
		
		cout << "Case #" << tt+1 << ": " << res << endl;
	}
    

  return 0;

}


