//TC

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>

#define forn(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define forr(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define foreach(a,b) for( typeof( (b).begin() ) a=(b).begin(); (a)!=(b).end() ; (a)++ )
#define foreachr(a,b) for( typeof( (b).rbegin() ) a=(b).rbegin(); (a)!=(b).rend() ; (a)++ )
#define dg(x)  cerr <<#x<<':'<<x<<" "
#define dbg(x)  cerr <<#x<<':'<<x<<endl
#define SET(A,b) memset(A,b,sizeof (A) )
#define SIZE(A) ((int)(A).size())
#define ALL(A) (A).begin(),(A).end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define num(a) (1LL<<(a))
using namespace std;

typedef double dbl;
typedef long long Lint;
typedef pair<int,int> ii;
typedef pair<Lint,Lint> Lii;

const Lint mod = 1e9;

int A,B,K;

Lint dn[40][3][3][3];

bool val( bool a,Lint b ){
	
	//~ printf("val %d %Ld\n",a,b);
	if(a && !b)
		return 1;
	if(a && b)
		return 0;
	return 0;
	
}

Lint f(int x,int a,int b,int k){
	
	//~ printf(" f %d %d %d %d\n",x,a,b,k);
	
	if( x==-1 )	return 1;
	
	Lint &rev=dn[x][a][b][k];
	
	if(rev!=-1)	return rev;
	
	rev=0;
	
	/*if( a==0 && b==0 && k==0 )
		return rev=num(x+1)*num(x+1);
	*/
	if(k){
		//~ puts("1");
		if( num(x)&K )
		{
			//~ puts("a");
			if( ( !a || num(x)&A ) && ( !b || num(x)&B ) )
				rev+=f( x-1,a,b,1 );
			if( ( !a || num(x)&A ) )
				rev+=f( x-1 , a  , val( b , num(x)&B ) ,0 );
			if( ( !b || num(x)&B ) )
				rev+=f( x-1 , val( a , num(x)&A ) , b, 0 );
			rev+=f(x-1 , val( a , num(x)&A ) , val( b , num(x)&B ), 0 );
		}
		else
		{
			//~ puts("b");
			if( ( !a || num(x)&A ) )
				rev+=f( x-1 , a  , val( b , num(x)&B ) ,1 );
			if( ( !b || num(x)&B ) )
				rev+=f( x-1 , val( a , num(x)&A ) , b, 1 );
			rev+=f(x-1 , val( a , num(x)&A ) , val( b , num(x)&B ), 1 );
		}
		
	}
	else{
		//~ puts("2");
		if( ( !a || num(x)&A ) && ( !b || num(x)&B ) )
				rev+=f( x-1,a,b,0 );
		if( ( !a || num(x)&A ) )
			rev+=f( x-1 , a  , val( b , num(x)&B ) ,0 );
		if( ( !b || num(x)&B ) )
			rev+=f( x-1 , val( a , num(x)&A ) , b, 0 );
		rev+=f(x-1 , val( a , num(x)&A ) , val( b , num(x)&B ), 0 );
	}
	
	//~ printf(" f %d %d %d %d -> %Ld\n",x,a,b,k,rev);
	
	return rev;
	
}

int main(){
	
	int T;
	
	scanf(" %d",&T);
	
	forn(test,1,T){
		
		printf("Case #%d: ",test);
		
		scanf("%d %d %d",&A,&B,&K);
		A--;
		B--;
		K--;
		
		//~ K=min(K,min(A,B));
		
		SET(dn,-1);
		
		cout << f(30,1,1,1) << endl;
		
	}
	
	return 0;
	
}
