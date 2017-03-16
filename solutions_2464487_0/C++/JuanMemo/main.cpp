#include<stdio.h>
#define PI 3.1416

int casos;
long long int r,radio,mili;

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&casos);
	for(int i = 1;i <= casos;i++){
		r = 0;
		scanf("%lld %lld",&radio,&mili);
		while(mili > 0){
			mili -= ((radio+1)*(radio+1)) -(radio*radio);
			radio += 2;
			if(mili >= 0){
				r++;
			}
		}
		printf("Case #%d: %lld\n",i,r);
	}
	return 0;
}
