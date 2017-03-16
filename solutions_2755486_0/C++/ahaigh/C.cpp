#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cassert>
#include <set>
#include <iomanip>
using namespace std;

#include "gmpxx.h"
typedef mpz_class big;

#define REP(i,n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MP make_pair
#define PB push_back

struct attack {
	ll d, w, e, s;
	attack() { }
	attack(ll _d, ll _w, ll _e, ll _s) {
		d = _d;
		w = _w;
		e = _e;
		s = _s;
	}
	bool friend operator <(const attack& a, const attack& b) {
		return a.d < b.d;
	}
};
attack query[1000005];
ll cm[2000005];
int k = 0;

//const int N = (1<<21)*8; //FIX!!!!!
const int N = 256*8;
ll val[N], here[N];

ll glob;
ll get_min(int a, int b, int id, int l, int r, ll now) {
	if (a <= l && r <= b) {
		glob = min(glob, max(now,val[id]));
	} else if (r <= a || b <= l) {
		return ((ll)1)<<60;
	} else {
		get_min(a, b, 2*id, l, (l+r)/2, max(now,val[id]));
		get_min(a, b, 2*id+1, (l+r)/2, r, max(now,val[id]));
	}
}

void set_max_range(int a, int b, ll x, int id, int l, int r) {
	if (a <= l && r <= b) {
		//update
		here[id] = max(here[id], x);
	} else if (r <= a || b <= l) {
		//nothing
	} else {
		set_max_range(a, b, x, 2*id, l, (l+r)/2);
		set_max_range(a, b, x, 2*id+1, (l+r)/2, r);
		//update
	}
	val[id] = max(here[id], min(val[2*id], val[2*id+1])); //overflow index????
}

int T, n;
map<ll,int> inv, f;
vector<int> day[700005];

int main() {
	cin >> T;
	REP(ttt,T) {
		cin >> n;
		k = 0;
		
		ll d, att, w, e, s, delta_d, delta_p, delta_s;
		REP(i,n) {
			//cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> delta_d[i] >> delta_p[i] >> delta_s[i];
			cin >> d >> att >> w >> e >> s >> delta_d >> delta_p >> delta_s;
			REP(j,att) {
				//register
				query[k] = attack(d, w, e, s);
				cm[2*k] = w;
				cm[2*k+1] = e;
				k++;
				
				//update
				d += delta_d;
				w += delta_p;
				e += delta_p;
				s += delta_s;
			}
		}
		
		sort(cm, cm+(2*k));
		int uniq = unique(cm, cm+(2*k))-cm;
		//compress here
		inv.clear();
		f.clear();
		REP(i,uniq) {
			inv[ cm[i] ] = i;
			f[i] = cm[i];
		}
		
		ll max_day = 0;
		sort(query, query+k);
		REP(i,k) {
			query[i].w = inv[ query[i].w ];
			query[i].e = inv[ query[i].e ];
			day[ query[i].d ].PB(i);
			max_day = max(max_day, query[i].d);
		}
		
		int succ = 0;
		CL(here);
		CL(val);
		REP(i,max_day+1) {
			if (day[i].size()) {
				/*cout << "!" << i << "---- ";
				REP(j,uniq) {
					glob = ((ll)1)<<60;
					get_min(j, j+1, 1, 0, uniq, 0);
					cout << glob << " ";
				}
				cout << endl;
				
				REP(j,30) cout << here[j] << " "; cout << endl;
				REP(j,30) cout << val[j] << " "; cout << endl;*/
			}
			
			//count
			REP(k, day[i].size()) {
				int j = day[i][k];
				//cout << f[query[j].w] << " " << f[query[j].e] << " " << query[j].s << endl;
				
				glob = ((ll)1)<<60;
				get_min(query[j].w, query[j].e, 1, 0, uniq, 0);
				if (glob < query[j].s) {
					succ++;
					//cout << "!" << endl;
				}
			}
			
			//update
			REP(k, day[i].size()) {
				int j = day[i][k];
				set_max_range(query[j].w, query[j].e, query[j].s, 1, 0, uniq);
			}
			
			day[i].clear();
		}
		cout << "Case #" << (ttt+1) << ": " << succ << endl;
		
		//return 0;
	}
}
