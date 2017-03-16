//By Lin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<cctype>
#include<cmath>

#define eps 1e-9
#define N 100010
#define sqr(x) ((x)*(x))
#define Rep(i,n) for(int i = 0; i<n; i++)
#define foreach(i,n) for( __typeof(n.begin()) i = n.begin(); i!=n.end(); i++)
#define X first
#define Y second
#define mp(x,y) make_pair(x,y)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;


double	p[10];
int		data[10],n,m,K;

double	ok(int i,int j,int k){
	Rep(t,K) p[t] = 0;
	Rep(a,2) Rep(b,2) Rep(c,2){
		int now = (a==0?1:i)*(b==0?1:j)*(c==0?1:k);
		Rep(i,K)
			if ( data[i] == now ) p[i]+= 0.5*0.5*0.5;
	}
	double	ret = 1;
	Rep(t,K) ret *= p[t];
	return ret;
}

bool	check( double &x , double y ){
	if ( y > x ) {
		x = y;
		return true;
	}
	return false;
}
void	solve(){
	double now = 0;
	int	ansi = 2, ansj = 2 , ansk = 2;
	if ( n == 1 ) {
		for(int i = 2; i<=m; i++) 
			if ( check(now,ok(i,1,1)) )
				ansi = i;
		printf("%d\n" , ansi );
	}
	else if ( n == 2 ) {
		for(int i = 2; i<=m; i++) 
			for(int j = 2; j<=m; j++)
				if ( check(now,ok(i,j,1)) )
					ansi = i , ansj = j;
		printf("%d%d\n" , ansi , ansj );
	}
	else{
		for(int i = 2; i<=m; i++) 
			for(int j = 2; j<=m; j++)
				for(int k = 2; k<=m; k++)
					if ( check(now,ok(i,j,k)) )
						ansi = i , ansj = j, ansk = k;
		printf("%d%d%d\n" , ansi , ansj, ansk );
	}
}
int		main(){
	int cas,tt = 0,R;
	scanf("%d", &cas );
	while ( cas -- ) {
		scanf("%d%d%d%d", &R, &n, &m , &K );
		printf("Case #%d:\n", ++tt );
		while ( R -- ) {
			Rep(i,K) scanf("%d", &data[i] );
			solve();
		}
	}
	return 0;
}
