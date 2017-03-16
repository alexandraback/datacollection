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

const int MAXN = 110;

bool used[MAXN][MAXN];

int ar[MAXN][MAXN];

int N,M;

int f(int x,int y){
	
	bool flag = true;
	
	forn(i,1,M)
		if(!used[x][i] && ar[x][i]!=ar[x][y])
			flag=false;
	
	if(flag){
		forn(i,1,M)
			used[x][i]=true;
		return 0;
	}
	
	flag=true;
	
	forn(i,1,N)
		if(!used[i][y] && ar[i][y]!=ar[x][y])
			flag=false;
	
	if(flag){
		forn(i,1,N)
			used[i][y]=true;
		return 0;
	}
	
	return 1;
	
}

int main(){
	
	int T;
	
	scanf(" %d",&T);
	
	forn(Case,1,T){
		
		scanf("%d %d",&N,&M);
		
		forn(i,1,N)
			forn(j,1,M)
				scanf(" %d",&ar[i][j]);
		
		SET(used,0);
		
		printf("Case #%d: ",Case);
		
		forn(l,1,100)
		{
			forn(i,1,N)
				forn(j,1,M)
					if(ar[i][j]==l && !used[i][j])
						if(f(i,j))
						{
							printf("NO\n");
							goto END;
						}
		}
		
		printf("YES\n");
		
END:;
	}
	
	return 0;
	
}
