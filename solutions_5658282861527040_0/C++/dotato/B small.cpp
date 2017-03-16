#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int test,tc=1,ans,a,b,k,i,j;
	
	for( scanf("%d",&test) ; test-- ;){
		scanf("%d%d%d",&a,&b,&k);
		
		ans=0;
		for( i=0 ; i<a ; i++ ){
			for( j=0 ; j<b ; j++ ){
				if( (i&j)<k ){
					ans++;
				}
			}
		}
		
		printf("Case #%d: ",tc++);
		printf("%d\n",ans);
		
	}
	
	return 0;
}

