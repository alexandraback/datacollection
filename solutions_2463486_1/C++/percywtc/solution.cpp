#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define CLR(a) memset(a,0,sizeof(a));
const LL MAX=31622776;
LL A,B;
int T,t,V[MAX+5],C[20];
bool check(LL K) {
	CLR(C); int p=0;
	while (K) {
		C[++p]=K%10;
		K/=10;
	}
	bool ok=1;
	for (int i=1;i<=p/2;i++) if (C[i]!=C[p-i+1]) ok=0;
	return ok;
}
int main () {
	scanf("%d",&T);
	for (LL i=1;i<=MAX;i++) 
		if (check(i)) if (check(i*i)) {
			V[i]=1;
		}
	for (int i=1;i<=MAX;i++) V[i]+=V[i-1];
	for (int t=1;t<=T;t++) {
		scanf("%lld%lld",&A,&B);
		A=ceil(sqrt(A));
		B=floor(sqrt(B));
		printf("Case #%d: %d\n",t,V[B]-V[A-1]);
	}		
	scanf("\n");
	return 0;
}
