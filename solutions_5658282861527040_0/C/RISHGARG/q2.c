#include<stdio.h>
typedef long long ll;
int main(){
	int t,l=1;
	scanf("%d",&t);
	while(l<=t){
		int a,b,k,i,j;
		ll cnt=0;
		scanf("%d%d%d",&a,&b,&k);
		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				if((i&j)<k)
					cnt++;
			}
		}
		printf("Case #%d: %lld\n",l,cnt);
		l++;
	}
	return 0;
}