#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define N 110
bool matrix[N][N];
void f(int nodes, int n) {
	// cout<<"sdfa "<<nodes<<endl;
	for(int i=2 ; i<nodes ; i++) {
		for(int k=2 ; k<i ; k++)
			matrix[i][k] = true;
		matrix[i][n] = true;
		matrix[1][i] = true;
	}
	matrix[1][n] = true;
}
int main() {
	int T, n;
	scanf("%d", &T);
	LL m;
	for(int caso=1 ; caso<=T ; caso++) {
		memset(matrix, false, sizeof(matrix));
		cin>>n>>m;
		LL maximo = 1LL << ((LL)n - 2LL);
		if( maximo >= m ) {
			printf("Case #%d: POSSIBLE\n", caso);
			int bits = 0;
			LL index = 0;
			for(LL i = 0LL ; i<60LL ; i++)
				if( m & (1LL<<i) ) { 
					bits++;
					index = i;
				}
			if( bits == 1 ) {
				// cout<<"pot"<<endl;
				f(index + 2, n);
			} else {
				f(index + 2, n);
				matrix[1][n - 1] = true;
				for(LL i=0 ; i<index ; i++) {
					if( m & (1LL<<i) ) {
						if( i == 0LL ) {
							matrix[n - 1][n] = true;
						} else {
							matrix[n - 1][i + 2] = true;
						}
					}	
				}
			}
			for(int i=1 ; i<=n ; i++) {
				for(int k=1 ; k<=n ; k++) {
					if( matrix[i][k] ) cout<<"1";
					else cout<<"0";
				}
				cout<<endl;
			}
		} else {
			printf("Case #%d: IMPOSSIBLE\n", caso);		
		}
	}
	return 0;
} 
