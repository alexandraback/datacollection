#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long lint;

lint n, a[1000], b[1000];
bool sol[1000];
map<lint, lint> mapa, mapb;

void main() {
	freopen("b-small-attempt6.in", "r", stdin);
	freopen("b-small.out", "w", stdout);
	//freopen("b-large.in", "r", stdin);
	//freopen("b-large.out", "w", stdout);

	lint T; cin>>T;
	lint a1, b1, cur, pos, solved;
	bool possible;
	for (lint t=1; t<=T; t++) {
		possible = true;
		cur = pos = solved = 0;
		memset(sol, 0, sizeof(sol));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		cin>>n;
		for (lint i=0; i<n; i++) {
			cin>>a[i]>>b[i];
			a[i] = (a[i]*1000 + i) * 10000 + 10000 - b[i];
			b[i] = b[i]*1000 + i;
		}
		sort(a, a+n);
		sort(b, b+n);

		mapa.clear();
		lint tmp;
		for (lint i=0; i<n; i++) {
			a[i] /= 10000;
			tmp = a[i]%1000;
			a[i] /= 1000;
			mapa[tmp] = i;
		}

		mapb.clear();
		for (lint i=0; i<n; i++) {
			tmp = b[i]%1000;
			b[i] /= 1000;
			mapb[i] = tmp;
		}

		for (lint i=0; possible && i<n; i++) {
			while (possible && cur < b[i]) {
				lint j;
				for (j=n-1; j>=i; j--) {
					if (cur >= a[ mapa[ mapb[i] ] ]) {
						cur++;
						sol[mapa [ mapb[i] ] ] = true;
						solved++;
					}
				}

				if (j<i) {
					possible = false;
					break;
				}
			}

			cur++;
			if (!sol[ mapa[ mapb[i] ] ]) {
				cur++;
			}
			sol[ mapa[ mapb[i] ] ] = true;
		}

		printf("Case #%d: ", t);
		if (possible) {
			cout<<solved+n<<endl;
		}
		else {
			cout<<"Too Bad"<<endl;
		}
	}
}
