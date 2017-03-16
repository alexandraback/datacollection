#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;


void solve(){
	long long k, c, s;
	scanf("%lld %lld %lld", &k, &c, &s);

	if( c == 1 ){
		if( k > s ) puts("IMPOSSIBLE");
		else {
			for(int i=1; i<=k; i++)
				printf("%d ", i);
			puts("");
		}
	}else{
		int st = k;
		if( s  >= ((k+1)/2) ){
			for(int i=0; i<(k+1)/2; i++){
				printf("%d ", st - i);
				st += k;
			}
			puts("");
		}else{
			puts("IMPOSSIBLE2");
		}
	}
}
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int R=1; R<=T; R++){
		printf("Case #%d: ", R);
		solve();
	}
}