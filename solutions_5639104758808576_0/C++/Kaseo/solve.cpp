#include <cstdio>

const int N = 1005;
char s[N];

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int R=1; R<=T; R++){
		int n;
		scanf("%d %s", &n, s);

		
		int c = 0, re = 0;
		for(int i=0; i<n+1; i++){
			if( c >= i ){
				c += (s[i]-'0');
			}else{
				re += i-c;
				c = i;
				c += (s[i]-'0');
			}
		}
		printf("Case #%d: ", R);
		printf("%d\n", re);
		
	}
}