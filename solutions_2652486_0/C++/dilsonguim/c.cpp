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
	//ios::sync_with_stdio(false);	
	int ntc;
	scanf("%d", &ntc);
	FORN(tc, 0, ntc){
		int r, n, m, k;
		scanf("%d%d%d%d", &r, &n, &m, &k);
		vector<int> p(k);
		vector<int> hits(k);
		printf("Case #%d:\n", tc + 1);
		int bestscore = 0;
		vector<int> bestss(n);
		FORN(gi, 0, r){
			FORN(i, 0, k) scanf("%d", &p[i]);

			int base = m - 1;
			vector<int> ss(n + 1);
			while(not ss[n]){
				FORN(i, 0, k) hits[i] = 0;
				FORN(mask, 0, 1 << n){
					int prod = 1;
					FORN(i, 0, n) if((mask >> i) & 1) prod *= ss[i] + 2;
					FORN(i, 0, k) if(p[i] == prod) hits[i]++;
				}
				
				int score = 1;
				FORN(i, 0, k) score *= hits[i];
				if(score > bestscore){
					bestscore = score;
					FORN(i, 0, n) bestss[i] = ss[i];
				}

				ss[0]++;
				int pc = 0;
				while(pc < n and ss[pc] == base){
					ss[pc] = 0;
					pc++;
					ss[pc]++;
				}
				
			}

			sort(ALL(bestss));
			FORN(i, 0, n) printf("%d", bestss[i] + 2);
			printf("\n");

		}
	}
}
