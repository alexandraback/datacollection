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
#define mm 1101000

const double zero=0.000000001;

int T,n;
int a[mn],p[mn],v[mm];

int main()
{
	freopen("C-small.in","r",stdin);
	freopen("C-small.out","w",stdout);
	cin >> T ;
	rp( Test,1,T )
	{
		memset( v , 0 , sizeof v );
		cin >> n;
		rp( i,1,n ) cin >> a[i] ;
		p[1]=1; 
		rp( i,2,n ) p[i]=p[i-1] << 1;
		int m=1 << n; --m;
		rp( i,0,m ) rp( j,1,n ) if ( p[j] & i ) v[i]+=a[j];
		bool ok=0;
		cout << "Case #" << Test << ":" << endl;
		rp( i,0,m ) if ( ! ( v[i] & 1 ) )
		{
			for ( int j=i ; j ; (--j)&=i ) if ( (v[j] << 1)==v[i] ) 
            {
				rp( k,1,n ) if ( p[k] & j ) cout << a[k] << " " ;
				cout << endl;
				j=i-j;
				rp( k,1,n ) if ( p[k] & j ) cout << a[k] << " " ;
				cout << endl;
                ok=1; break;
                } // 0 - 0
			if ( ok ) break;
		} // 0 - 0
		if ( !ok ) cout << "Impossible" << endl;
	} // 0 - 0
} // 0 - 0 