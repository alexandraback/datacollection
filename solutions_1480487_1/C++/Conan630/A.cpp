#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define rp(i,l,r) for ( int i=(int)(l); i<=(int)(r); ++i )
#define dp(i,l,r) for ( int i=(int)(l); i>=(int)(r); --i )
#define rpt(i,t) for ( typeof(t.begin()) i=t.begin(); i!=t.end(); ++i )
#define In insert
#define Co count
#define Fi first
#define Se second
#define PB push_back
#define MP make_pair

const int dx[]={1,-1,0,0};
const int dy[]={0,0,-1,1};

typedef long long LL;
typedef vector < int > VI;
typedef vector < string > VS;
typedef vector < LL > VL;
typedef vector < double > VD;
typedef pair < int , int > PII;

#define inf 10000000
#define mn 210

const double zero=0.000000001;

int T,n;
int a[mn];

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	cin >> T ;
	rp( Test,1,T )
	{
		cin >> n ;
		int S=0;
		rp( i,1,n ) cin >> a[i] , S+=a[i];
		cout << "Case #" << Test << ":" ;
		rp( i,1,n )
		{
			double l=0 , r=1 ;
			while ( l+zero<=r )
			{
				double mid=(l+r)/2;
				double sum=1 , temp=mid*S+a[i];
				rp( j,1,n )
				{
					if ( temp<a[j] ) continue;
					double tmp=temp-a[j];
					tmp/=S;
					sum-=tmp;
				} // 0 - 0
				if ( sum<=zero ) r=mid; else l=mid;
			} // 0 - 0
			printf(" %.6f",l*100);
		} // 0 - 0
		cout << endl;
	} // 0 - 0
} // 0 - 0 