#include <stdio.h>

int main(){

	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	
	int test,tc=1,ans,x,r,c,l;
	
	for( scanf("%d",&test) ; test-- ; printf("Case #%d: %s\n",tc++,ans?"GABRIEL":"RICHARD") ){
		scanf("%d%d%d",&x,&r,&c);
		
		if( x==1 ) ans=1;
		else if( x>=7 ) ans=0;
		else{
			l = r*c;
			if( l%x ) ans=0;
			else{
				if( x==6 ){
					if( l<24 ) ans=0;
					else if( r<4 || c<4 ) ans=0;
					else ans=1;
				}
				else{
					x--;
					if( r<x || c<x ) ans=0;
					else ans=1;
				}
			}
		}	
	}

	return 0;
}

