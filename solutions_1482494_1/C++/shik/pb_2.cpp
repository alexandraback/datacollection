// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[N],b[N],s[N];
int main()
{
	int t,cas=0;
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%d",&n);
		for ( int i=0; i<n; i++ ) scanf("%d%d",a+i,b+i);
		int ans=0,now=0;
		memset(s,0,sizeof(s));
		while ( now<2*n ) {
			ans++;
			int w=-1;
			for ( int i=0; i<n&&w==-1; i++ ) if ( s[i]<2 && now>=b[i] ) w=i;
			if ( w!=-1 ) {
				now+=2-s[w];
				s[w]=2;
				continue;
			}
			for ( int i=0; i<n; i++ ) if ( s[i]<1 && now>=a[i] && (w==-1||b[i]>b[w]) ) w=i;
			if ( w==-1 ) break;
			now++;
			s[w]=1;
		}
		if ( now<2*n ) printf("Case #%d: Too Bad\n",++cas);
		else printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}
