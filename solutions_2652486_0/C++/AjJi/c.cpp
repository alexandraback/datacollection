#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define REP(i,a) for(int i=0;i<(int)(a);i++)
#define ALL(i) i.begin(),i.end()
#define rALL(i) i.rbegin(),i.rend()
#define PB push_back

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

template<class T> string i2a(T x) {ostringstream oss; oss<<x; return oss.str();}



int main()
{

   freopen("C-small-1-attempt0.in","r",stdin);
   freopen("C-small-1-attempt0.out","w",stdout);

	int t;
	scanf("%d",&t);
	int r,n,m,k;
	scanf("%d %d %d %d", &r, &n, &m, &k);
	printf("Case #1:\n");
	REP(cas, r) {
		vector<int> prods;
		REP(j, k) {
			int tmp; scanf("%d",&tmp);
			prods.PB(tmp);
		}


		vector<int> occ(m+1, 0);
		vector<int> index;
		occ[0] = occ[1] = -1000;
		REP(i,occ.size()) index.PB(i);
		for(int i = 2; i <= m; i++) {
			REP(j, prods.size()) {
				int p = prods[j];
				if(p%i == 0) occ[i]++;
			}
		}

		REP(i, occ.size()) {
			FOR(j, i + 1, occ.size()) {
				if(occ[i] < occ[j]) {
					swap(occ[i], occ[j]);
					swap(index[i], index[j]);
				}
			}
		}


		REP(i,n) {
			printf("%d", index[i]);
		}
		printf("\n");
	}


    return 0;
}
