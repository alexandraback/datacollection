#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <iomanip>
#include <climits>

using namespace std;

struct Attack {
	int w;
	int e;
	int h;
};

struct Army {
	int d;
	int n;
	int w;
	int e;
	int s;
	int d_d;
	int d_p;
	int d_s;
};

bool sort_at(const Attack &t1, const Attack &t2) {
	return t1.w < t2.w;
}

int main() {
	int numCases;
	cin >> numCases;

	Army a[10];
	Attack t[100];

	for(int c = 0; c < numCases; c++) {
		int N;
		cin >> N;

		int attacks = 0;
		int tc = 0;
		for(int i = 0; i < N; i++) {
			cin >> a[i].d >> a[i].n >> a[i].w >> a[i].e >> a[i].s >> a[i].d_d >> a[i].d_p >> a[i].d_s;
			attacks += a[i].n;
		}

		int suc = 0;
		for(int d = 0; d < attacks; d++) {
			int start_tc = tc;
			// Find attackers
			int min_d = INT_MAX;
			for(int i = 0; i < N; i++) {
				if ( a[i].n > 0 )
					min_d = min(min_d, a[i].d);
			}

			sort(t, t + tc, sort_at);

			for(int i = 0; i < N; i++) {
				//cout << "Day " << min_d << " attacks" << endl;
				if( a[i].n > 0 && a[i].d == min_d ) {
					// Attack
					//bool blocked = false;
					int aw = a[i].w;
					int ae = a[i].e;
					for(int k = 0; k < start_tc; k++) {
						//cout << "Evaluating attack " << k+1 << " from " << t[i].w << " to " << a[i].e << " with " << a[i].s << endl;
						if ( t[k].h >= a[i].s ) {
							if ( t[k].w > aw ) {
								break;			
							}
							aw = max( t[k].e, aw );
						}
					}

					if ( aw < ae ) {
						//cout << "Tribe " << i+1 << " successful from " << a[i].w << " to " << a[i].e << " with " << a[i].s << endl;
						suc++;
					}

					t[tc].e = a[i].e;
					t[tc].w = a[i].w;
					t[tc].h = a[i].s;
					tc++;

					// Update
					a[i].d += a[i].d_d;
					a[i].s += a[i].d_s;
					a[i].e += a[i].d_p;
					a[i].w += a[i].d_p;
					a[i].n -= 1;
				}
			}
		}

		printf("Case #%d: ", c+1);
		cout << suc << endl;
	}

	return 1;
}