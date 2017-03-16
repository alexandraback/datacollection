#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define MX 10000001

using namespace std;
typedef long long _ll;

typedef std::pair<_ll,int> pp;

_ll v[MX];

bool comp ( const pp& l, const pp& r)
   { if(l.first != r.first) return l.first < r.first;
   else return l.second < r.second; }


int T;
_ll E, R, N;

int main() {
	cin >> T;
	for(int c=1;c<=T;c++) {
		cin >> E >> R >> N;
		for (int i =0;i<N;i++) {cin >> v[i];}

		_ll ce = E;
		int ci = 0;
		_ll rw = 0;
		while (ci < N) {
			int ni = ci + 1;
			while (ni < N && v[ni] <= v[ci]) ni++;

			if ((ni - ci) * R >= E || ni >= N) {
				rw += ce * v[ci];
				ci++;
				ce = 0;
			} else {
				_ll spend = ce - (E - (ni - ci) * R);
				if (spend < 0) spend = 0;
				rw += spend * v[ci];
				ci++;
				ce -= spend;
			}
			ce += R;
		}


		printf("Case #%d: %lld\n", c, rw);
	}
}
