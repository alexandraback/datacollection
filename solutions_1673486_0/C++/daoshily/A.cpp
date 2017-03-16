#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define N 110000

using namespace std;


int n,m,test,cas = 1,ans,cnt;
double p[N];

double work(){
	scanf("%d%d",&n,&m);
	double P = 1,best = 2+m;
	for ( int i = 0 ; i < n ; i++ ){
		scanf("%lf",&p[i]);
		P *= p[i];
	}
	p[n] = 1;
	for ( int i = 0 ; i <= n ; i++ ){
		P /= p[n-i];
		best = min(best,(double)i+m+i-n+1+(m+1)*(1-P));
	}
	return best;
}
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	for ( scanf("%d",&test) ; cas <= test ; cas++ ){
		printf("Case #%d: ",cas);
		double ans = work();
		printf("%.6lf\n",ans);
	}
}
