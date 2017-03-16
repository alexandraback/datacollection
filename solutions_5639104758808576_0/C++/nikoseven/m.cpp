#include <cstdio>

char s[2000];
int n;

int main() {
	int T,ics=0;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%s",&n,s);
		int c = s[0] - '0',ans = 0;
		int last = n;
		while( s[last] == '0' )
			--last;
		for(int i=1;i<=last;++i) {
			if( c >= i ) {
				c += s[i] - '0';
			}
			else {
				ans += i-c;
				c += i - c;
				c += s[i] - '0';
			}
		}
		printf("Case #%d: %d\n",++ics,ans);
	}
	return 0;
}