#include <stdio.h>
#include <cstring>

const int L = 105;
char s[L];

char inv( char t ){
	if( t == '+' ) return '-';
	else return '+';
}

int get( int x, char t ){
	
	for(int i=x; i>=0; i--){
		if( s[i] != t )
			return get( i, inv(t) ) + 1;
	}
	return 0;
}


void solve(){
	scanf("%s", s);
	int l = strlen( s );
	printf("%d\n", get( l-1, '+' ));
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