#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define CLR(a) memset(a,0,sizeof(a));
const int MAX=105;
int M,N,A[MAX],V,S[MAX],R[MAX],T;
int solve() {
	scanf("%d%d",&M,&N);
	V=N;
	for (int i=1;i<=N;i++) scanf("%d",A+i);
	sort(A+1,A+N+1);
	CLR(S); CLR(R);
	R[0]=M;
	if (M==1) return V;
	else {
		for (int i=1;i<=N;i++) {
			if (R[i-1]>A[i]) {
				R[i]=R[i-1]+A[i];
				S[i]=S[i-1];
			}		
			else {
				int k=R[i-1],c=0;
				for (;k<=A[i];k=k*2-1,c++);
				S[i]=S[i-1]+c;
				R[i]=k+A[i];
			}
		}		
	}
	for (int i=0;i<=N;i++) V=min(V,S[i]+N-i);
	return V;
}
int main () {
	scanf("%d",&T);
	for (int t=1;t<=T;t++) printf("Case #%d: %d\n",t,solve());
	scanf("\n");
	return 0;
}
