#include <bits/stdc++.h>
using namespace std;
#define LL long long
int T,K,C,S;
int main(){
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++){
		printf("Case #%d:",tt);
		scanf("%d%d%d",&K,&C,&S);
		for (int i=1;i<=S;i++)
			printf(" %d",i);
		printf("\n");
	}
}