#include <bits/stdc++.h>
#define M 2500

using namespace std;

bool ck[M+1];
int n;

void input(void){
	int i,j,x;
	scanf("%d",&n);
	for(i=1;i<=M;i++) ck[i]=false;
	for(i=1;i<=n*2-1;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&x);
			ck[x]=!ck[x];
		}
	}
}

void output(void){
	int i;
	for(i=1;i<=2500;i++) if(ck[i]) printf("%d ",i);
	printf("\n");
}

int main(void){
	freopen("input.txt","r",stdin);

	int t,i;

	scanf("%d",&t);
	for(i=1;i<=t;i++){
		input();
		printf("Case #%d: ",i);
		output();
	}

	return 0;
}
