#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <stdio.h>
#include <stack>

using namespace std;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORE(i,n) for (int i=0; i<=n; ++i)
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define REPE(i,a,b) for (int i=a; i<=b; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define mp make_pair
#define pb push_back
#define INF (1e9)

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;
const double pi = acos(-1.0);
const int inf =(int) 1e9;

const double eps = 1e-4;
const int ss=(int)1e6+3;
const int base=inf;

bool pred (const int& i, const int& j) 
{
	return i>j;
}


int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
	//freopen("symposium.in","r",stdin);
    //freopen("symposium.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);

	FOR(tt,t) {
		printf("Case #%d: ",tt+1);
		int a,n;
		scanf("%d%d",&a,&n);
		VI z(n);
		FOR(i,n) {
			scanf("%d",&z[i]);
		}
		SORT(z);
		if (a==1) {
			printf("%d\n",n);
			continue;
		}
		int res = inf;
		int plus = 0;
		LL all = a;
		int k = 0;
		while(k<n) {
			if (all>z[k]) {
				all += z[k];
				++k;
			} else {
				res = min(res,n-k+plus);
				++plus;
				all += (all-1);
			}
		}
		if (res != inf) 
			printf("%d\n",min(res,plus));
		else
			printf("0\n");
	}
#ifdef _DEBUG
    fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#endif
    return 0;
}

