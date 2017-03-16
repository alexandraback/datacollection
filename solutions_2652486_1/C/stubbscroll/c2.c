#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long ll;
int R,N,M,K;
int prod[100];

int num[20];
int factor[120],fn;

ll ans,L,Z;

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

int analyze() {
	int i,j,P;
	char found[12];
	memset(found,0,K);
	for(i=0;i<(1<<K);i++) {
		P=1;
		for(j=0;j<N;j++) if(i&(1<<j)) P*=num[j];
		for(j=0;j<N;j++) if(prod[j]==P) found[j]=1;
	}
	for(j=0;j<N;j++) if(!found[j]) return 0;
	for(j=ans=0;j<N;j++) ans=ans*10+num[j];
	return 1;
}

void dosomething() {
	int i,j;
	if(rand()%4==0) {
		
	}
}

int main() {
	int T,i,j;
	scanf("%d",&T);
	scanf("%d %d %d %d",&R,&N,&M,&K);
	printf("Case #%d:\n",T);
	while(R--) {
		for(i=0;i<K;i++) scanf("%d",&prod[i]);
		ans=-1;
		L=1;
		for(i=0;i<K;i++) L=lcm(L,prod[i]);
		Z=L;
		fn=0;
		for(i=M;i>=2;i--) while(L%i==0) factor[fn++]=i,L/=i;
		while(fn<N) {
			factor[fn++]=5;
			if(fn==N) break;
			for(i=0;i<N;i++) if(factor[i]==8) {
				factor[i]=2;
				factor[fn++]=4;
				break;
			}
			if(fn==N) break;
			for(i=0;i<N;i++) if(factor[i]==6) {
				factor[i]=2;
				factor[fn++]=3;
				break;
			}
			if(fn==N) break;
			for(i=0;i<N;i++) if(factor[i]==4) {
				factor[i]=2;
				factor[fn++]=2;
				break;
			}
			factor[fn++]=8;
			if(fn==N) break;
			factor[fn++]=6;
		}
		for(i=0;i<1;i++) {
			for(j=0;j<N;j++) num[j]=factor[j];
			if(analyze()) goto ok;
			dosomething();
		}
		for(ans=i=0;i<N;i++) ans=ans*10+factor[i];
	ok:
		printf("%I64d\n",ans);
	}
	return 0;
}
