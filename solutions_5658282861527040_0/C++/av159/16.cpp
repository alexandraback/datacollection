#include<stdio.h>
#include<string.h>

int main(){
	int t,z,i,j,c,a,b,k;
	scanf("%d",&t);
	for(z=1;z<=t;z++){
		scanf("%d %d %d",&a,&b,&k);
		c=0;
		for(i=0;i<a;i++)
			for(j=0;j<b;j++)
				if((i&j)<k)
					c++;
		printf("Case #%d: %d\n",z,c);
	}
	return 0;
}
