#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<float.h>
using namespace std;
#define PII pair<int,int>
#define LL long long
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,n)
#define EPS 1e-9
int n, m;
LL r, t;
double find(){
	double R = r, T = t;
	return (1 - 2 * R + sqrt((2 * R - 1) * (2 * R - 1) + 8 * T)) / 4;
}
int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		int ans = 0;
		scanf("%lld%lld", &r, &t);
		double k = find(), R = r, T = t, k2 = (LL)k;
		k2++;
		if ( 2 * k2 * k2 + k2 * (2 * R - 1) - T < EPS) k++;
		else if ( 2 * k * k + k * (2 * R - 1) - T > EPS) k--;
		printf("Case #%d: %lld\n", cc, (LL)k);
	}
	return 0;
}

