#include <bits/stdc++.h>

using namespace std;

int k,c,s;

void input(void){
	scanf("%d %d %d",&k,&c,&s);
}

long long pows(int x,int p){
	if(p==0) return 1ll;
	long long m=pows(x,p>>1);
	m*=m;
	if(p&1) m*=x;
	return m;
}

void process(void){
	if(k<=c*s){
		int i,j;
		for(i=1;i<=k;){
			long long su=0;
			for(j=1;j<=c;j++,i++){
				su+=(min(i,k)-1)*pows(k,c-j);
			}
			printf("%lld ",su+1);
		}
		printf("\n");
	}else{
		printf("IMPOSSIBLE\n");
	}
}

int main(void){
	freopen("input.txt","r",stdin);

	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		input();
		printf("Case #%d: ",i);
		process();
	}

	return 0;
}
