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
typedef pair<int,int> pii;
typedef long long int tint;

#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define rall(c) (c).rbegin(), (c).rend()
#define all(c) (c).begin(), (c).end()
#define D(a) << #a << "=" << a << " "


#define si(a) int((a).size())
#define pb push_back
#define mp make_pair
#define MAXN 2000

struct attack {
	tint d;
	tint w,e;
	tint s;	
	attack(tint d,tint w,tint e,tint s): d(d),w(w),e(e),s(s) {}
};


void print(attack a) {
	cout << a.d << " " << a.w << " " << a.e << " " << a.s << endl;
}

bool comp(attack a,attack b) {
	return a.d < b.d;
}

tint W[MAXN];
tint cero = 1000;
tint res;
vector <attack> A;
vector <attack> R;

inline void build() {
	forn(i,si(R)) {
		forsn(j,2*R[i].w,2*R[i].e+1) { 
			//cout << "max " << W[cero+j] << " " <<R[i].s << endl;
			W[cero+j] = max(W[cero+j],R[i].s);
		}
	}	
	R.clear();
}

inline void go(attack a) {
	bool yes = false;
	forsn(i,2*a.w,2*a.e+1) 
		if (W[cero+i] < a.s) yes = true;
	if (yes) { R.pb(a); res++; }
}

inline void simulate() {
	tint last = -1;
	forn(i,si(A)) {
		if (A[i].d != last) build();		
		//forsn(j,-100,100) cout << " W[i] = " << j << " " << W[cero+j] << endl;
		//cout << "******************************" << endl;
		last = A[i].d;
		go(A[i]);
	}
}


int main () {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	
    int cases;
    cin >> cases;
    
    
   
    forn(tt,cases) {	
		forn(i,MAXN) W[i] = 0;
		res = 0;
		
		A.clear();
		R.clear();
		
		tint N,di,ni,wi,ei,si,delta_di,delta_pi,delta_si;
		cin >> N;
		forn(_,N) {
			cin >> di >> ni >> wi >> ei >> si >> delta_di >> delta_pi >> delta_si;
			forn(i,ni) {
				A.pb(attack(di,wi,ei,si));				
				di += delta_di;
				wi += delta_pi;
				ei += delta_pi;
				si += delta_si;
			}
		}
		
		sort(all(A),comp);				
		simulate();			
		
		cout << "Case #" << tt+1 << ": " << res << endl;
	}
    

  return 0;

}


