#include<stdio.h>

#define S(x) ((x)*(x))

int main(){
	int t,r,n,add,sum,count,k=0;
	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	
	while(t--){
		scanf("%d%d",&r,&n);
		
		add=S(r+1)-S(r);
		count = add;
		sum=0;
		for(;add<=n;add+=count){
			count+=4;
			sum++;
			
		}
		
		printf("Case #%d: %d\n",++k,sum);
	
	}
	return 0;
}
