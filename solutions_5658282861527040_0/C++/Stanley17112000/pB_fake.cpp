#include <stdio.h>
#include <string.h>
int T , A , B , K , C = 1;
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&T);
	while ( T-- ){
		int ans = 0;
		scanf("%d%d%d",&A,&B,&K);	
		for ( int i = 0 ; i < A ; i++ )
			for ( int j = 0 ; j < B ; j++ )
				if ( (i & j) < K )
				   ans++;
		printf("Case #%d: %d\n",C++,ans);
	}
	
	return 0;	
}
