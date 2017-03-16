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

#define NDEBUG
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
	int ntc;
	scanf("%d", &ntc);
	FORN(tc, 0, ntc){
		int n;
		scanf("%d", &n);
		int s[n];
		FORN(i, 0, n)
			scanf("%d", s + i);

		int vtf = -1;
		set<int> psums;
		FORN(ss, 0, 1 << n){
			int p = 0;
			int css = ss;
			int sum = 0;
			while(css){
				if(css & 1) sum += s[p];
				p++;
				css >>= 1;
			}
			if(psums.find(sum) != psums.end()){
				vtf = sum;
				WATCH(sum);
				break;
			}
			psums.insert(sum);
		}
		vector<set<int> > sets;
		if(vtf == -1) goto end;
		FORN(ss, 0, 1 << n){
			int p = 0;
			int css = ss;
			int sum = 0;
			while(css){
				if(css & 1) sum += s[p];
				p++;
				css >>= 1;
			}
			if(sum == vtf){
				WRITE("sum!!! " << sum << " " << vtf);
				set<int> ssum;
				int css = ss;
				int p = 0;
				while(css){
					if(css & 1) ssum.insert(s[p]);
					p++;
					css >>= 1;
				}
				sets.push_back(ssum);
				if(sets.size() > 1) break;
			}
		}
		end:
		printf("Case #%d:\n", tc + 1);
		if(sets.empty())
			printf("Impossible");
		else{
			FOREACH(e, sets){
				FOREACH(x, *e){
					if(x == e->begin()){
						printf("%d", *x);
					}else{
						printf(" %d", *x);
					}
				}
				printf("\n");
			}
		}

	}
}
