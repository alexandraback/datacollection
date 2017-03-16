#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


/* Prewritten code begins */
#define VI          vector<int>
#define SCI(x)      scanf("%d",&x)
#define REP(i,n)    for(int i=0; i<(n); ++i)
/* Prewritten code ends */

VI a, b, vis1, vis2;
int main() {
	int T, N, index1, index2, best1, stars, done, res;

	SCI(T);
	REP(cs,T) {
		SCI(N);

		a.resize(N);
		b.resize(N);
		REP(i,N) SCI(a[i]), SCI(b[i]);

		vis1.assign(N, 0);
		vis2.assign(N, 0);
		res = N; stars = 0;
		while(stars < 2*N) {
			done = 0;
			index1 = index2 = -1;
			best1 = INT_MIN;

			REP(i,N) {
				if(!vis1[i] && !vis2[i] && b[i] <= stars) {
					stars += 2;
					vis1[i] = vis2[i] = 1;
					done = 1;
				}
				if(!vis2[i] && b[i] <= stars) {
					index2 = i;
				}
				if(!vis1[i] && a[i] <= stars && best1 < b[i]) {
					best1 = b[i];
					index1 = i;
				}
			}
			if(done) continue;
			else if(index2 != -1) {
				stars += 1;
				vis2[index2] = 1;
			} else if(index1 != -1) {
				stars += 1;
				vis1[index1] = 1;
				res++;
			} else { res = INT_MAX; break; }
		}

		printf("Case #%d: ", cs+1);
		if(res != INT_MAX) printf("%d\n", res); else printf("Too Bad\n");
	}
	return 0;
}
