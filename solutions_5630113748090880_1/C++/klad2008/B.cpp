#include <bits/stdc++.h>
using namespace std;
const int maxn=2500;
int T,N,x;
bool a[3010];
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++){
		scanf("%d",&N);
		memset(a,0,sizeof(a));
		for (int i=1;i<2*N;i++)
			for (int j=1;j<=N;j++){
				scanf("%d",&x);
				a[x]=!a[x];
			}
		printf("Case #%d:",tt);
		for (int i=1;i<=maxn;i++)
			if (a[i])printf(" %d",i);
		printf("\n");
	}
}