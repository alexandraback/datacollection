#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
#include <iostream>
 
using namespace std;
 
//const int INF = 5003;
const long long INF = 1000000007;
const int MAXN = 100005;
typedef pair <int, int> ii;
//typedef pair <long long, long long> ii;
long long gcd( long long b, long long s ){
    return (s!=0) ? gcd( s, b%s ) : b;
}

long long f[505];
string s[105];
int l[105];
int alp[35];
int a[35][35];
int deg[35];
long long c[35];

long long go( int x ){
	for(int i=0; i<26; i++)
		if( x != i && a[x][i] ) 
			return (f[c[x]]*go( i ))%INF;
	return f[c[x]];
}

long long get( int x ){
	for(int i=0; i<26; i++)
		if( x != i && a[x][i] )
			return (c[x]+get( i ))%INF;
	return c[x];
}

long long  A, B, C;
  
long long pow(long long a, long long b){
    if(b>1){
        a=pow(a, b/2);
        a=(a*a)%C;
        if(b&1)
            a=(a*A)%C;
    }
    return a%C;
}

long long comb( long long n, long long k ){
	
	long long ret = f[n];
	if( n-k < 0 ) 
		return 1;
	A = f[n-k];
	B = INF-2;
	C = INF;
	ret = (ret * pow(A, B)) % INF;
	A = f[k];
	B = INF-2;
	C = INF;
	ret = (ret * pow(A, B)) % INF;
	return ret;
}

int main(){ freopen("in.txt", "r",  stdin);
	freopen("out.txt", "w", stdout);

	
	f[0] = 1;
	for(int i=1; i<500; i++)
		f[i] = (f[i-1]*i) % INF;
		
	int T;
	scanf("%d", &T);
	for(int R=1; R<=T; R++){
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			cin >> s[i];
			l[i] = s[i].length();
		}
		memset( alp, 0, sizeof( alp ) );
		memset( a, 0, sizeof( a ) );
		memset( deg, 0, sizeof( deg ) );
		memset( c, 0, sizeof( c ) );

		
		for(int i=0; i<n; i++){
			char prev = s[i][0];	
			for(int j=1; j<l[i]; j++){
				if( prev != s[i][j] ){
					++a[prev-'a'][s[i][j]-'a'];
					++deg[s[i][j]-'a'];
				}
			}
		}

		bool can = 1;
		for(int i=0; i<26; i++){
			if( deg[i] >= 2 )
				can = 0;
		}
		int scc = 0;
		long long res = 1;
		if( can ) {
			for(int i=0; i<n; i++){
				bool can = 1;
				for(int j=0; j<l[i]; j++){
					if( s[i][0] != s[i][j] )	
						can = 0;
					
					alp[s[i][j]-'a'] = 1;
				}
				if( can )
					++c[s[i][0]-'a'];
			}
			int N = 0;
			for(int i=0; i<26; i++)
				N += c[i];
		
		
			for(int i=0; i<26; i++){
				if( deg[i] == 0 && alp[i] ) {
					
						
				
					
					res = (res * go( i )) % INF;
					++scc;
				}
			}
		}
		else
			res = 0;
		
		res = (res * f[scc]) %INF;
		printf("Case #%d: ", R);
		printf("%lld\n", res%INF);
	}
}  