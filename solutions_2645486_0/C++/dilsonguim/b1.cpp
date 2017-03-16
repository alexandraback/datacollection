#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//#define NDEBUG
#if defined(NDEBUG)
#define DBG_CODE(cb...)
#else
#define DBG_CODE(cb...) cb
#endif
#define WRITE(x) DBG_CODE(cout << x << endl)
#define WATCH(x) DBG_CODE(cout << #x << "=" << x << endl)
#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); i++)
#define ALL(x) x.begin(), x.end()
#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

int main(){
	ios::sync_with_stdio(false);
	int ntc;
	scanf("%d", &ntc);
	FORN(tc, 0, ntc){
		int e, r, n;
		scanf("%d%d%d", &e, &r, &n);
		vector<int> v(n);
		FORN(i, 0, n) scanf("%d", &v[i]);

		int best = 0;
		vector<int> p(n + 1);
		while(not p[n]){

			bool ok = true;
			int value = 0;
			int energy = e;
			FORN(i, 0, n){
				if(p[i] > energy){
					ok = false;
					break;
				}
				value += p[i] * v[i];
				energy = min(e, energy - p[i] + r);
			}
			best = max(best, value);

			int pc = 0;
			p[pc]++;
			while(pc < n and p[pc] == e + 1){
				p[pc] = 0;
				pc++;
				p[pc]++;
			}
		}

		printf("Case #%d: %d\n", tc + 1, best);
	}
	
}
