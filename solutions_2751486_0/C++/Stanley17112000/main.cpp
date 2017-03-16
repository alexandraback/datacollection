#include <string.h>
#include <stdio.h>
#include <math.h>
int T , DP[100001] , n, ans, C = 1;
char G[100001];
bool check[255];
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	check['a'] = check['e'] = check['i'] = check['o'] = check['u'] = true;
	scanf("%d",&T);
	while ( T-- ){
		scanf("%s",G);
		scanf("%d",&n);
		ans = 0;
		int len = strlen( G );
		for ( int i = 0 ; i + n <= len ; i++ ){
			int avail = 0 , cnt = 0;
			for ( int j = i ; j < len ; j++ ){
				if ( !avail ){
					if ( !check[G[j]]  )
						cnt++;
					else cnt = 0;
					if ( cnt == n )
						avail = true;
				}
				if ( avail ){
					ans += len - j;
					break;
				}
			}

		}
		printf("Case #%d: %d\n",C++,ans);
		
	}
	return 0;
}