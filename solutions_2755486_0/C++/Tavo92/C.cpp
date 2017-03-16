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
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define forn(a, n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define forall(a, all) for(typeof((all).begin()) a = (all).begin(); a != (all).end(); ++a)

#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define dforsn(a,s,n) for(int a = (n)-1; a>=(s); --a)
#define dforall(a, all) for(typeof((all).rbegin()) a = (all).rbegin(); a != (all).rend(); ++a)

#define contains(mask, bit) ((mask & (1LL<<bit)) != 0LL)

typedef long long tint;

struct att{
	tint day, w, e, s; 
	
	att(int a, int b, int c, int d){day = a; w = b; e = c; s = d;}
};

bool operator<(const att& a0, const att &a1){
	return a0.day < a1.day;
}

map<tint,tint> wall, wall2;
int T;

int main()
{
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);

	cin >> T;
	
	forn(p,T){
		wall.clear();
		int N;
		cin >> N;
		//cerr << p << endl;
		vector<att> attacks;
		forn(i,N){
			tint d,n,w,e,s,delD,delP,delS;
			cin >> d >> n >> w >> e >> s >> delD >> delP >> delS;
			
			forn(j,n){
				attacks.push_back(att(d,w*2,e*2,s));
				d += delD;
				e += delP; w += delP;
				s += delS;
			}
		}
		//cerr << p << endl;
		sort(attacks.begin(), attacks.end());
		wall2.clear();
		int ret = 0, vd = 0;
		forn(i,attacks.size()){
			//cerr << attacks[i].w << " " << attacks[i].e << endl;
			//cout << attacks[i].day << " " << ret << endl;
			bool pasa = true;
			if(attacks[i].day > vd){
				vd = attacks[i].day;
				wall = wall2;
			}
			
			forsn(k,attacks[i].w,attacks[i].e+1){
				if(wall[k] < attacks[i].s){
					pasa = false;
					wall2[k] = max(wall2[k],attacks[i].s);
				}
			}
			
			if(!pasa) ret++;
		}
		
		printf("Case #%i: %i\n", p+1, ret);
	}
	
	return 0;
}
