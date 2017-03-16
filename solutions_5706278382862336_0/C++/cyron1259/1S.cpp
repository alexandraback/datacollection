#include <stdio.h>
int t;
long long int p,q,x;
int div2(){
	int cnt=0;
	x=1;
	while(q%2==0){
		q/=2;
		x*=2;
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int k;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		scanf("%lld/%lld",&p,&q);
		printf("Case #%d: ",k);
		int n=div2();
		if(p%q==0){
			p/=q;
			int cnt=0;
			while(p){
				if(p>=x) break;
				x/=2;
				cnt++;
			}
			printf("%d\n",cnt);
		}
		else printf("impossible\n");
	}
	return 0;
}