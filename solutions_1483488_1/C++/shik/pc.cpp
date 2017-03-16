// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define N 10000010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
bool vis[N];
LL f( int x, int a, int b ) {
	char s[30];
	sprintf(s,"%d",x);
	LL c=0;
	for ( int i=0,n=strlen(s); i<n; i++ ) if ( s[i]!='0' ) {
		int t=0;
		for ( int j=0; j<n; j++ ) t=t*10+s[(i+j)%n]-'0';
		if ( vis[t] ) continue;
		vis[t]=1;
		if ( a<=t && t<=b ) c++;
	}
	return c*(c-1)/2;
}
int main()
{
	int T,cas=0,a,b;
	scanf("%d",&T);
	while ( T-- ) {
		scanf("%d%d",&a,&b);
		memset(vis,0,sizeof(vis));
		LL ans=0;
		for ( int i=a; i<=b; i++ ) if ( !vis[i] ) ans+=f(i,a,b);
		printf("Case #%d: %lld\n",++cas,ans);
	}
	return 0;
}
