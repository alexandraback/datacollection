#include<cstdio>
#include<cassert>
#include<cstring>
#include<map>
#include<set>
#include<time.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include <limits>
   
using namespace std;
  
long long gcd( long long b, long long s ){
    return (s!=0) ? gcd( s, b%s ) : b;
}
  
long long Pow( long long a, long long b, long long c ){
    if( b == 0 ) return 1%c;
    else if( b == 1 ) return a%c;
    else{
        long long A = Pow( a, b/2, c );
        A = (A*A) % c;
        if( b & 1 ) A = (A*a) % c;
        return A;
    }
}

const long long INF = 1e9 + 7;
const long long INF9 = 1e9 + 9;
typedef pair <int, int> ii;

char a[105], t[105];

int b[105];
double p[105][105];

void pre( int l ){
	int i = 0, j = -1;
	b[0] = -1;
	while( i < l ){
		while( j > -1 && t[i] != t[j] )
			j = b[j];
		i++, j++;
		b[i] = j;
	}

}

void solve_large(){
	int k, l, s;
	scanf("%d %d %d", &k, &l, &s);
	scanf("%s", a);
	scanf("%s", t);

	pre( l );
	
	for(int i=0; i<=s; i++)
		for(int j=0; j<=s; j++)
			p[i][j] = 0.0;
	p[0][1] = 1.0;
	double re = 0.0;
	for(int i=0; i<s; i++){
		for(int j=0; j<=s; j++){
			for(int q=0; q<k; q++){
				int jj = j-1;
				while( jj >= 0 && a[q] != t[jj] )
					jj = b[jj];
				++jj;
				if( jj == l ){
					re += p[i][j]/k;
					jj = b[j];
				}
				p[i+1][jj+1] += p[i][j]/k;	
					
			}
		}
	}
	double mx = 1.0 + (s-l)/(l-b[l]);
	for(int i=0; i<l; i++){
		bool ok = 0;
		for(int j=0; j<k; j++)
			if( t[i] == a[j] ){
				ok = 1;
				break;
			}
		if( !ok ) {
			mx = 0;
			break;
		}
	}
		
	printf("%.9lf\n", mx-re);
}
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++){
		printf("Case #%d: ", R);
		solve_large();
	}
}
