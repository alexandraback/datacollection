#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long llong;

const llong INF = 0x7fffffffffffffffLL;

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int TT;
	scanf("%d", &TT);
	for(int cas = 1;cas <= TT; ++cas){
		llong r, t;
		scanf("%lld %lld", &r, &t);
		llong lb = 0;
		llong ub = min(t / (2 * r + 1), llong(sqrt(double(t))));
		while(lb < ub){
			llong mid = (lb + ub + 1) / 2;
			llong val = 2 * mid * mid + (2 * r - 1) * mid;
			if(INF - 2 * mid * mid  < (2 * r - 1) * mid){
				fprintf(stderr, "overflow\n");
				while(true);
			}
			if(val <= t) lb = mid;
			else ub = mid - 1;
		}
		printf("Case #%d: %lld\n", cas, lb);
	}
	return 0;
}