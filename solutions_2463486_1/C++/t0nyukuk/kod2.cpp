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

vector<Lint> ar,A;

void kont(Lint a){
	
	int x=0;
	Lint S=a*a;
	
	int tmp[100];
	
	while(S){
		tmp[++x]=S%10;
		S/=10;
	}
	
	forn(i,1,x)
		if(tmp[i]!=tmp[x-i+1])
			return ;
	
	A.pb(a);
	ar.pb(a*a);
	
}

Lint P[20];

void f(int k,int l,Lint t){
	
	if(l%2==0 && k<=(l+1)/2 )
	{
		kont(t);
		return ;
	}
	if(l%2==1 && k<(l+1)/2 )
	{
		kont(t);
		return ;
	}
	
	if(k==l){
		if( l==1 )
			forn(i,1,9)
				f( k-1,l,t+P[k-1]*i );
		else
			forn(i,1,9)
				f( k-1,l,t+P[k-1]*i+P[l-k]*i );
	}
	else{
		if( l%2 && (l+1)/2==k )
			forn(i,0,9)
				f( k-1,l,t+P[k-1]*i );
		else
			forn(i,0,9)
				f( k-1,l,t+P[k-1]*i+P[l-k]*i );
	}
	
}

int main(){
	
	P[0]=1LL;
	
	forn(i,1,10)
	{
		P[i]=P[i-1]*10LL;
	}
		
	
	f( 1 , 1 , 0 );
	f( 2 , 2 , 0 );
	f( 3 , 3 , 0 );
	f( 4 , 4 , 0 );
	f( 5 , 5 , 0 );
	f( 6 , 6 , 0 );
	f( 7 , 7 , 0 );
//	f( 8 , 8 , 0 );
//	f( 9 , 9 , 0 );
	
//	Lint n;
	
//	dbg( SIZE(A) );
	
	sort(A.begin(),A.end());
	sort(ar.begin(),ar.end());
	
//	forn(i,0,SIZE(A)-1)
//		printf("%Ld    %Ld\n",A[i],ar[i]);
	
/*	forn(i,0,SIZE(A)-1)
		printf("%Ld\n",A[i]);*/
	
	int T;
	
	scanf(" %d",&T);
	
	Lint a,b;
	
	forn(Case,1,T){
		
		scanf("%Ld %Ld",&a,&b);
		
		printf("Case #%d: ",Case);
		
		printf("%d\n",upper_bound(ALL(ar),b)-lower_bound(ALL(ar),a));
		
	}
	
	return 0;
	
}
