#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
 
using namespace std;
 
const long long INF = 1000000007;
typedef pair <int, int> ii;

int a[55][55];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){// freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++){
		int r, c, m, rr, cc, mm;
		scanf("%d %d %d", &r, &c, &m);
		rr = r, cc = c, mm = m;

		memset( a, 0, sizeof( a ) );
		bool swp = 0, ff = 1;
		a[1][1] = 0;
		while( mm > 0 ){
			if( rr >= cc ){
				for(int i=cc; i>=1; i--){
					if( mm > 0 ){
						a[rr][i] = 1;
						--mm;
					}
					else{
						if( i == 1 ){
							if( rr-1 >= 3 )
								swap( a[rr-1][cc], a[rr][i+1] );
							else if( rr-1 == 2 )
								ff = 0;
						}
						break;
					}
				}
				--rr;
			}
			else{
				for(int j=rr; j>=1; j--){
					if( mm > 0 ){
						a[j][cc] = 1;
						--mm;
					}
					else{
						if( j == 1 ){
							if( cc-1 >= 3 ){
								swap( a[rr][cc-1], a[j+1][cc] );
								swp = 1;
							}
							else if( cc-1 == 2 )
								ff = 0;
						}
						break;
					}
				}
				--cc;
			}
		}

		a[1][1] = 2;
		
		printf("Case #%d:\n", R);
		
		if( (r != 1) && (c != 1) && (r*c-m != 1) && ( !ff || (r*c-m == 2 && !(r==1) && !(c==1) ) || 
			(r*c-m == 3 || (r*c-m == 5)) || (((r*c-m) & 1) && (r == 2 || c == 2) ) ) )
			puts("Impossible");
		else{
			for(int i=1; i<=r; i++){
				for(int j=1; j<=c; j++){
					if( a[i][j] == 2 )
						printf("c");
					else if( a[i][j] == 1 )
						printf("*");
					else
						printf(".");
				}
				puts("");
			}
		}
	

	}

}