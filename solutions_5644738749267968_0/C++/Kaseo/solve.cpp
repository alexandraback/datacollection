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
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

double a[1005], b[1005];
bool c[1005];

int main(){// freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++){
		
		
		int n;
		scanf("%d", &n);

		for(int i=0; i<n; i++)
			scanf("%lf", a+i);
		for(int i=0; i<n; i++)
			scanf("%lf", b+i);

		sort( a, a+n );
		sort( b, b+n );

		int dw = 0, w = n;
		memset( c, 0, sizeof( c ) );

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if( !c[j] && b[j] < a[i]){
					c[j] = 1;
					++ dw;
					break;
				}
			}
		}
		memset( c, 0, sizeof( c ) );


		for(int j=0; j<n; j++){
			for(int i=n-1; i>=0; i--){
				if( !c[i] && a[i] < b[j] ){
					c[i] = 1;
					-- w;
					break;
				}
			}
		}
			
		printf("Case #%d: ", R);
		printf("%d %d\n", dw, w);
	}

}