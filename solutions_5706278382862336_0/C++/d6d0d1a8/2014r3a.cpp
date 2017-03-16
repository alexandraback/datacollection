#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=0;tt<t;tt++){
		int m,n;
		scanf("%d/%d",&m,&n);
		int c=n;
		while(c%2==0)c/=2;
		if(c!=1)printf("Case #%d: impossible\n",tt+1);
		else{
		c=n;
		int r=0;
		while(m<c){
			r++;
			c/=2;
		}
		printf("Case #%d: %d\n",tt+1,r);
		}
	}
	return 0;
}