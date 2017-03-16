#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <cmath>
#include <list>
#include <map>
#include <set>

#define maxn 55
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define fill(x,y) memset((x),(y) ,sizeof(x))
#define type(x) __typeof(x.begin())
#define sz(x) x.size()
#define o ((f+l)/2)
#define umax(x,y) (x)=max((x),(y))
#define NEW(x) (x *)calloc(1,sizeof(x))
#define umin(x,y) (x)=min((x),(y));
#define tmax(x,y,z) max((x),max((y),(z))) 
#define tmin(x,y,z) min((x),min((y),(z))) 
#define PI (acos(-1)) 

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int Lint;
int N,M,R,K,yon[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
char we[maxn][maxn];
vector<ii> er;

int cnt( int i , int j )
{
	if( er[i].fi+yon[j][0]>0 && er[i].fi+yon[j][0]<=N &&
	 er[i].se+yon[j][1]>0 && er[i].se+yon[j][1]<=M ) return 1;
	else return 0;
}
int dfs( int a , int need )
{
	//~ printf("%d %d\n",a,need);
	if( !need ){
		for( int i=1 ; i<=N ; i++,puts("") )
			for( int j=1 ; j<=M ; j++ ){
				if( i==1 && j==1 )
					printf("%c",'c');
				else if( we[i][j] )
					printf("%c",'.');
				else 
					printf("%c",'*');
			}
		return 1;
	}
	for( int i=a ; i<sz(er) ; i++ )	{
		int mines=0;
		for( int j=0 ; j<8 ; j++ )
			if( cnt( i , j ) && !we[er[i].fi+yon[j][0]][er[i].se+yon[j][1]] )
				mines++;
		if( mines<=need ){
			for( int j=0 ; j<8 ; j++ )
				if( cnt( i , j ) && !we[er[i].fi+yon[j][0]][er[i].se+yon[j][1]] ){
					we[er[i].fi+yon[j][0]][er[i].se+yon[j][1]]=a;
					er.pb( ii( er[i].fi+yon[j][0] , er[i].se+yon[j][1] ) );
				}
				
			int k=dfs( i+1 , need-mines );
			
			for( int j=0 ; j<8 ; j++ )
				if( cnt( i , j ) && we[er[i].fi+yon[j][0]][er[i].se+yon[j][1]]==a ){
					we[er[i].fi+yon[j][0]][er[i].se+yon[j][1]]=0;
					er.pop_back();
				}
			if( k )
				return 1;
		}
	}
	return 0;
}
int main ()
{
	//~ freopen("","r",stdin);
	//~ freopen("","w",stdout);
	scanf("%d",&K);
	
	for( int k=1 ; k<=K ; k++ ){
		scanf("%d %d %d",&N,&M,&R);
		R=N*M-R;
		er.pb(ii(-1,-1));
		er.pb( ii( 1 , 1 ) );
		we[1][1]=1;
		printf("Case #%d:\n",k);
		if( !dfs( 1 , R-1 ) ) 
			printf("Impossible\n");
		er.clear();
	}
	
	
	return 0;
}
