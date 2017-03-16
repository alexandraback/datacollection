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

#define maxn 15
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
int T,K,N,er[30],used[maxn];
Lint ans=0,MOD=10e9+7;
string s[maxn];

void f( int a , string ss )
{
	if( a==N ){
		//~ for( int i=0 ; i<sz(ss) ; i++ )
			//~ printf("%c",ss[i]);
		//~ puts("");
		for( int i=0 ; i<=26 ; i++ )
			er[i]=0;
		for( int i=0 ; i<sz(ss) ; er[ss[i]-'a']=1,i++ )
			if( i && ( ss[i]!=ss[i-1] && er[ss[i]-'a'] ) )
				return ;
		ans++;
		ans%=MOD;
		return ;
	}
	for( int i=1 ; i<=N ; i++ )
		if( !used[i] /*&& ( !a || ss[sz(ss)-1]==s[i][0] )*/ ){
			used[i]=1;
			f( a+1 , ss+s[i] );
			used[i]=0;
		}
	return ;
}
int main ()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	scanf("%d",&T); K=T;
	while( T-- ){
		scanf("%d",&N);
		for(int i=1 ; i<=N ; i++ )
			cin >> s[i];
		printf("Case #%d: ",K-T);
		string a;
		
		ans=0;
		f( 0 , a );			
		
		cout << ans << endl ; 
		
	}
	
	return 0;
}
