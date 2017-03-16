#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for(int R=1; R<=T; R++){
		int x, r, c;
		scanf("%d %d %d", &x, &r, &c);
		
		if( r > c ) swap( r, c );

		bool ok = 1;
		if( (r*c)%x == 0 ){
			int m = (x+1)/2;
			if( r >= m && c >= x ){
				if( r == m && x >= 4 ){
					int n = r*c/x;
					if( n <= 2 )
						ok = 0;
				}
			}else
				ok = 0;

		}else
			ok = 0;
		
		printf("Case #%d: ", R);
		if( ok ) puts("GABRIEL");
		else puts("RICHARD");

	}
}