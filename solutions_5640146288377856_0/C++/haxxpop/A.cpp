#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ; e< t ; e++){
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		int ans = 0;
		ans += (n-1)*(m/k);
		ans += m/k;
		ans += k;
		if( m%k == 0 ) ans--;
		printf("Case #%d: %d\n",e+1,ans);
	}
}
