#include <stdio.h>

int main(){

	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	
	int test,tc=1,ans,n,temp,i;
	char in[1002];
	
	for( scanf("%d",&test) ; test-- ; printf("Case #%d: %d\n",tc++,ans) ){
		scanf("%d",&n);
		scanf("%s",in);
		
		for( ans=temp=i=0 ; in[i] ; i++ ){
			if( temp<i ){
				ans++;
				temp++;	
			}
			temp += in[i]-48;
		}
		
	}

	return 0;
}

