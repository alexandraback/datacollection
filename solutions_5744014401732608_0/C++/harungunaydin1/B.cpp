#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end() 
#define MAXN 60
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
pii P[MAXN];
int K,M,N;
int B[MAXN] , In[MAXN];
bool flag;
bool A[MAXN][MAXN];

bool control() {

	memset( B , 0 , sizeof B );
	memset(In , 0 , sizeof In);
	queue < int > Q;

	Q.push(1);
	B[1] = 1;


	int i,j,x;

	FOR(i,1,N)
		FOR(j,i+1,N)
			if( A[i][j] )
				In[j]++;


	while( !Q.empty() ) {
		
		x = Q.front(); Q.pop();
		FOR(i,x+1,N)
			if( A[x][i] ) {
				B[i] += B[x];
				if( --In[i] == 0 )
					Q.push(i);	
			}
	}

	return B[N] == M;

}

void rec( int x ) {

	if( x == K + 1 ) {
		if( control() )
		{
			printf("POSSIBLE\n");

			int i,j;
			FOR(i,1,N){
				FOR(j,1,N)
					printf("%d" , A[i][j]);
				printf("\n");
			}

			flag = true;
		}
		return;
	}

	if( flag ) return;

	A[ P[x].f ][ P[x].s ] = true;
	rec(x+1);
	if( flag ) return;
	A[ P[x].f ][ P[x].s ] = false;
	rec(x+1);

}
void solve() {

	memset( A , 0 , sizeof A );
	flag = false;
	K = 0;

	N = read(); M = read();

	int i,j;
	FOR(i,1,N)
		FOR(j,i+1,N)
			P[++K] = make_pair(i,j);

	rec(1);

	if( !flag )
		printf("IMPOSSIBLE\n");

}
int main()
{
	freopen( "input.txt" , "r" , stdin );
	freopen( "output.txt" , "w" , stdout );
	int T = read(),i;
	FOR(i,1,T) {
		printf("Case #%d: " , i );
		solve();
	}
	return 0;
}
