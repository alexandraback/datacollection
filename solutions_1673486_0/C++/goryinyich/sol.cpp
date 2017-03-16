#pragma comment(linker, "/STACK:33554432")

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <memory.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define ABS(n) ((n)<0 ? -(n) : (n))
#define SQR(a) (a)*(a)
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define MP make_pair
#define PB push_back
#define FILL(a) memset(a,0,sizeof(a));
#define COPY(a,b) memcpy(a,b,sizeof (b));
#define SI(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define y1 yyyyy1
#define prev prevvvvv
#define LL long long
const double PI = 2*acos(0.0);
const double EPS = 1e-8;
const int INF = (1<<30)-1;

int tc, a, b;
double p[100000];
double cp[100001];

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> tc;
	REP(ic,tc){
		cin >> a >> b;
		REP(i,a) cin >> p[i];
		cp[0] = 1.;
		REP(i,a) cp[i+1] = cp[i]*p[i];

		double ans = b+2;
		for (int i = 0; i <= a; ++i){
			double expe = cp[i]*(a-i + (b-i) + 1) +
				(1.-cp[i])*(a-i + (b-i) + 1 + b + 1);
			ans = MIN(ans, expe);
		}

		printf ("Case #%d: %.10lf\n", ic+1, ans);
	}
	return 0;
};