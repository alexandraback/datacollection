#include <stdio.h>
#include <string.h>
long long s,e,save[50]={1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002,};
int main(){
	int test,testt,i,cnt;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&testt);
	for(test=1;test<=testt;test++){
		scanf("%lld %lld",&s,&e);
		cnt=0;
		for(i=0;i<50;i++){
			if(s<=save[i]*save[i] && save[i]*save[i]<=e)
				cnt++;
		}
		printf("Case #%d: %d\n",test,cnt);
	}
	return 0;
}
