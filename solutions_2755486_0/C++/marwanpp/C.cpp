/*
 * C.cpp
 *
 *  Created on: May 12, 2013
 *      Author: Marwan
 */

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstring>
#include <sstream>
#include <complex>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <climits>
#include <set>
#include <map>

using namespace std;

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
#define MP make_pair
#define SZ(x) (int)x.size()

int dcmp(double a, double b) {
	return (fabs(a - b) <= eps) ? 0 : ((a < b) ? -1 : 1);
}

typedef long long ll;
typedef pair<int, int> pii;

struct attack {
	int di;
	int w;
	int e;
	int s;

	bool operator< (const attack & at1) const {
		return di < at1.di;
	}

	void print() {
		cout << "wil attack on day " << di << endl;
		cout << "from " << w << " to " << e << endl;
		cout << "by Strength " << s << endl;
		cout << "  -------------------------   " << endl;
	}
};

int wall[10000] ;

struct dayAttacks {
	vector<attack> attacks ;
	int mxattack ;
};

void update (int s, int e, int v){
		for (int j=s ; j <= e ; j++)
			wall[j] = v ;
}

int getmin (int s, int e) {
	int mn = oo ;
	for (int i=s ; i <= e ; i++)
		mn = min (mn, wall[i]);

	return mn ;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
//	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cout << "Case #" << t + 1 << ": ";

		int n;
		cin >> n;

		vector<attack> attacks;

		for (int i = 0; i < n; i++) {
			int di, ni, wi, ei, si, d_di, d_pi, d_si;
			cin >> di >> ni >> wi >> ei >> si >> d_di >> d_pi >> d_si;

			wi += 1000 ;
			ei += 1000 ;
			wi *= 2 ;
			ei *= 2 ;
			d_pi *= 2;


			attack attack1 = { di, wi, ei, si };
			attacks.push_back(attack1);

			for (int j = 0; j < ni-1; j++) {
				(di += d_di), (wi += d_pi), (ei += d_pi), (si += d_si);
				attack attacki = { di, wi, ei, si};
				attacks.push_back(attacki);
			}
		}

		sort(attacks.begin(), attacks.end());
//
//		for (int i=0 ; i < SZ(attacks) ; i++)
//			attacks[i].print();

		memset (wall, 0, sizeof wall) ;

		vector <dayAttacks> v ;

		dayAttacks DA ;
		v.push_back(DA) ;

		for (int i=0 ; i < SZ(attacks) ; i++) {
			if (i && attacks[i-1] < attacks[i])
				v.push_back(DA);

			v.back().attacks.push_back(attacks[i]);
		}

		int cnt = 0 ;
		for (int i=0 ; i < SZ(v) ; i++) {
			vector <pair<pii, int> > updt ;

			for (int j=0 ; j < SZ(v[i].attacks) ; j++) {
				if (getmin(v[i].attacks[j].w, v[i].attacks[j].e) < v[i].attacks[j].s){
					cnt ++ ;
					updt.push_back(MP(MP(v[i].attacks[j].w, v[i].attacks[j].e), v[i].attacks[j].s));
				}
				else
				{
//					v[i].attacks[j].print();
//					for (int k=v[i].attacks[j].w ; k <= v[i].attacks[j].e ; k++)
//						cout << wall[k] << " " << k << " ";
//					cout << endl << endl ;
				}
			}

			for (int j=0 ; j < SZ(updt) ; j++)
				update(updt[j].first.first, updt[j].first.second, updt[j].second);
		}

		cout << cnt << endl ;
	}

	return 0;
}
