#include <bits/stdc++.h>
using namespace std;

int T;
char str[111];
int main(){
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%s",str);
		int N = strlen(str), f = 0, a = 0;
		for(int i=N-1; i>=0; i--){
			int c = str[i] == '+' ? 1 : 0;
			if( f ) c ^= 1;
			if( !c ){
				a++; f^=1;
			}
		}
		printf("Case #%d: %d\n", t, a );
	}
	return 0;
}
