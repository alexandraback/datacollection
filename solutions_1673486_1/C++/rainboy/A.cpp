#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MaxN=100000+500;

double a[MaxN];
int T,N,K;
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d", &T);
	for (int t=1;t<=T;t++){
		scanf("%d %d", &N, &K);
		for (int i=1;i<=N;i++)
		scanf("%lf", &a[i]);
		printf("Case #%d: ", t);
		double Ans=K+2,p=1.0;
		for (int i=1;i<=N;i++){
			p*=a[i];
			double x=p*double(N-i+K-i+1)+(1.0-p)*double(N+2*K-2*i+2);
			if (x<=Ans) Ans=x;
		}
		printf("%.6lf\n", Ans);
	}
	return 0;
}
