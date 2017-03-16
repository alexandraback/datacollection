#include <bits/stdc++.h>
#define M 10

using namespace std;

bool ck[M];
int n,t,cnt;

void check(int x){
	while(x){
		if(!ck[x%10]) cnt++, ck[x%10]=true;
		x/=10;
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int i,j,k=100;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		printf("Case #%d: ",i);
		if(n==0) printf("INSOMNIA\n");
		else{
			for(cnt=j=0;j<10;j++) ck[j]=false;
			for(j=1;j<=k;j++){
				check(j*n);
				if(cnt==10){
					printf("%d\n",j*n);
					break;
				}
			}
		}
	}
	return 0;
}
