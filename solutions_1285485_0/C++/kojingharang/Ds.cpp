#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << "\n";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

ll GCD( ll a, ll b ) {
	if(a<b) {
		ll tmp=a;
		a=b; b=tmp;
	}
	ll c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

int main() {
	int test_cases;
	cin>>test_cases;
	REP(ttt, test_cases) {
		int H,W,D;
		cin>>H>>W>>D;
		//cout<<H<<" "<<W<<" "<<D<<endl;
		
		int ox=0, oy=0;
		REP(h, H) {
			string s;
			cin>>s;
			REP(i, s.size()) if(s[i]=='X') {ox=i; oy=h;}
		}
		ox--;oy--;
		//cout<<ox<<" "<<oy<<endl;
		
		int ww = 100/(W-2)+1;
		int hh = 100/(H-2)+1;
		int ans = 0;
		vector<pair<int, PII> > l;
		for(int x=-ww;x<=ww;x++) {
			for(int y=-hh;y<=hh;y++) {
				int MX = x*(W-2)+(x%2==0 ? ox : W-2-ox-1)-ox;
				int MY = y*(H-2)+(y%2==0 ? oy : H-2-oy-1)-oy;
				int d = MX*MX+MY*MY;
				//if(d!=0 && d<=D*D) cout<<d<<"  "<<x<<" "<<y<<"    "<<MX<<" "<<MY<<endl;
				if(d!=0 && d<=D*D) l.PB(MP(d, MP(MX, MY)));
			}
		}
		//map<int, int> dh;
		
		sort(ALL(l));
		vector<PII> used;
		REP(i, l.size()) {
			int d = l[i].first;
			int MX=l[i].second.first;
			int MY=l[i].second.second;
			int ok=1;
			//cout<<"try "<<d<<" "<<MX<<" "<<MY<<endl;
			REP(j, used.size()) {
				int ux = used[j].first;
				int uy = used[j].second;
				if(MX*ux<0) continue;
				if(MY*uy<0) continue;
				if(ux==0) {
					if(MX!=0) continue;
					else {ok=0;break;}
				}
				if(uy==0) {
					if(MY!=0) continue;
					else {ok=0;break;}
				}
				int ug = GCD(ux, uy);
				int mg = GCD(MX, MY);
				if(ux/ug==MX/mg && uy/ug==MY/mg) {ok=0;break;}
			}
			if(ok) {
				//cout<<"X "<<d<<" "<<MX<<" "<<MY<<endl;
				//cout<<MX<<"\t"<<MY<<(MX==0 ? MY*10000000 : (double)MY/MX+(MX>0?1000:-1000))<<endl;
				//cout<<MX<<"\t"<<MY<<endl;
				ans++;
				used.PB(l[i].second);
				//dh[d]++;
			}
		}
		
		//vector<double> aa;
		//FOR(e, used) aa.PB(e->first==0 ? (double)e->second*1000000 : (double)e->second/e->first+(e->first>0?1000:-1000));
		//sort(ALL(aa));
		//REP(i, aa.size()-1) if(abs(aa[i]-aa[i+1]) < 0.00001) cout<<"ERROR"<<aa[i]<<" "<<aa[i+1]<<endl;
		//cout<<dh<<endl;
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
	}
	return 0;
}
