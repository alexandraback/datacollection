#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<list>
#include<algorithm>

using namespace std;

#define rp(i,l,r) for ( int i=(int)(l); i<=(int)(r); ++i )
#define dp(i,l,r) for ( int i=(int)(l); i>=(int)(r); --i )

typedef long long LL;

int Case;
LL  n,t;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	cin >> Case;
	rp( Casei,1,Case )
	{
		cin >> n >> t ;
		LL a=n*2+1;
		LL l=1 , r=t ;
		while ( l<=r ) 
		{
			LL mid=(l+r)>>1;
			LL temp=mid*2+a-2;
			if ( temp>t/mid ) r=mid-1; else l=mid+1;
		}
		cout << "Case #" << Casei << ": " << l-1 << endl;
	}
}