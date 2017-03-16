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

char res[10][100]={"X won","O won","Draw","Game has not completed"};

int N=4;

char ar[10][10];

int cnt;

int kont(char who){
	
	bool flag;
	
	forn(i,1,N)
	{
		flag=true;
		forn(j,1,N)
			if(ar[i][j]!=who && ar[i][j]!='T')
				flag=false;
		if(flag)
			return 1;
		
		flag=true;
		forn(j,1,N)
			if(ar[j][i]!=who && ar[j][i]!='T')
				flag=false;
		if(flag)
			return 1;
	}
	
	flag=true;
	forn(i,1,N)
		if(ar[i][i]!=who && ar[i][i]!='T')
			flag=false;
	if(flag)	return 1;
	flag=true;
	forn(i,1,N)
		if(ar[i][N-i+1]!=who && ar[i][N-i+1]!='T')
			flag=false;
	if(flag)	return 1;
	return 0;
	
}

int find(){
	
	bool flag=true;
	forn(i,1,N)
		forn(j,1,N)
			if(ar[i][j]=='.')
				flag=false;
	
	if( kont('X') && !kont('O') )	return 0;
	if( kont('O') && !kont('X') )	return 1;
	if( flag )	return 2;
	return 3;
	
}

int main(){
	
	int T;
	
	scanf(" %d",&T);
	
	forn(Case,1,T){
		
		printf("Case #%d: ",Case);
		
		forn(i,1,N)
			forn(j,1,N)
				scanf(" %c",&ar[i][j]);
		
		printf("%s\n",res[ find() ]);
				
	}
	
	return 0;
	
}
