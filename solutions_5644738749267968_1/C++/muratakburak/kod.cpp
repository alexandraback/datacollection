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

#define maxn 1010
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
typedef long double LD;
int N,M,used[maxn];
vector<LD> er,we;

int main ()
{
	//~ freopen("","r",stdin);
	//~ freopen("","w",stdout);
	scanf("%d",&N);
	for( int k=1 ; k<=N ; k++ ){
		scanf("%d",&M); LD a;
		for( int i=1 ; i<=M ; i++ ) {
			scanf("%Lf",&a);
			er.pb( a );
		}sort( all( er ) );
		for( int i=1 ; i<=M ; i++ ) {
			scanf("%Lf",&a);
			we.pb( a );
		}sort( all( we ) );
		
		int ans=0,res=0;
		for( int i=0,j=0 ; i<M ; i++ ){
			if( er[i]>we[j] ){
				ans++;
				j++;
			}
		}
		for( int i=M-1 ; i>=0 ; i-- )	{
			int bigger=-1;
			for( int j=0 ; j<M ; j++ )
				if( !used[j] && ( bigger==-1 || we[j]>er[i]) ){
					if( bigger==-1 ){
						bigger=j;
					}
					else{
						bigger=j;
						break;
					}
				}
			if( we[bigger]<er[i] )
				res++;
			used[bigger]=1;
		}
		printf("Case #%d: %d %d\n",k,ans,res);
		for( int i=0 ; i<M ; i++ )
			used[i]=0;
		er.clear(); we.clear();
	}
	
	return 0;
}
