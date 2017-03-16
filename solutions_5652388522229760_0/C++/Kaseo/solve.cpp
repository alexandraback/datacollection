#include <stdio.h>

int get(long long n){
	int st = 0;
	if( n == 0 ) return (1<<0);
	while( n ){
		st = st | (1<<(n%10));
		n /= 10;
	}
	return st;
}

void solve(){
	long long n;
	scanf("%lld", &n);
	
	if( n == 0 ){
		puts("INSOMNIA");
		return ;
	}
	int st = 0;
	for(long long i=1;; i++){
		st = st | get( n*i );
		if( st == (1<<10)-1 ) {
			printf("%lld\n", n*i);
			break;
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