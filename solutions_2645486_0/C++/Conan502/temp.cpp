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

const int mn=10100;

int Case;
int E,R,N;
int v[mn],num[mn];
int f[mn][10];

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	cin >> Case;
	rp( Casei,1,Case )
	{
		cin >> E >> R >> N ;
		rp( i,1,N ) cin >> v[i];
		memset( f , 0 , sizeof f );
		rp( i,0,E ) f[0][i]=-1000000;
		f[0][E]=0;
		rp( i,1,N ) 
		{
			rp( j,0,E ) rp( k,0,j ) f[i][j-k]=max( f[i][j-k] , f[i-1][j]+k*v[i] );
	//		rp( j,0,E ) cout << i << " " << j << " " << f[i][j] << endl;
			dp( j,E,R ) f[i][j]=max( f[i][j],f[i][j-R] );
	//		rp( j,0,E ) cout << i << " " << j << " " << f[i][j] << endl;
		}
		cout << "Case #" << Casei << ": " << f[N][0] << endl;
	}
}