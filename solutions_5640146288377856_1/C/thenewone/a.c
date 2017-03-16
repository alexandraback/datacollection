#include<stdio.h>
int main(){
	int t,n,r,c,w,T,i,j;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d%d%d",&r,&c,&w);
/*		if( c == w )
			printf("Case #%d: %d\n",t,c+r-1);
		else if( w == 1 )
			printf("Case #%d: %d\n",t,c*r);
		else{
*/
			i = c/w;
			j = c%(w);
			if( j ==  0    )
				j = w-1;
			else
				j = w;
			printf("Case #%d: %d\n",t,i*r + j);
//		}
	}
	return 0;
}
