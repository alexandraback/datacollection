#include <stdio.h>
using namespace std;

int main(){

	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);
	
	int test,tc=1,ans,n,temp,i,in,now,j;
	int cake[1002];
	
	for( scanf("%d",&test) ; test-- ; printf("Case #%d: %d\n",tc++,ans) ){
		scanf("%d",&n);
		for( ans=i=0 ; i<n ; i++ ){
			scanf("%d",&cake[i]);
			if( cake[i]>ans ) ans=cake[i];
		}
		
		for( i=ans-1 ; i>=2 ; i-- ){
			temp=0;
			for( j=0 ; j<n ; j++ ){
				temp += (cake[j]+i-1)/i-1;
			}
			if( i+temp<ans ) ans=i+temp;
		}
	}

	return 0;
}

