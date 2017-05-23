#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < n; i++)
#define forn1(i,n) for(int i = 1; i <= n; i++)
#define MAXX 100100
#define INF 1000000000
using namespace std;
double T,C,F,X;
int main(){
	double time, rate, best;
	scanf("%lf",&T);
	
	forn1(t,T){
		scanf("%lf%lf%lf", &C, &F, &X);
		int maxFarms = ceil(X / C)+1;
		time = 0;
		rate = 2;
		best = INF;
		forn1(i,maxFarms){
			best = min(best, time + X/rate);
			time = time + (C/rate);
			rate += F; 
		}
		printf("Case #%d: %.7lf\n", t, best);
	}
	return 0;
}
