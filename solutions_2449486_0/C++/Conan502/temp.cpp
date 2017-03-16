#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define rp(i,l,r) for ( int i=(int)(l); i<=(int)(r); ++i )
#define dp(i,l,r) for ( int i=(int)(l); i>=(int)(r); --i )

typedef long long LL;

const int mn=110;

int Case;
int n,m,mat[mn][mn];
bool ok;

bool Row( int x , int y )
{
	rp( i,1,m ) if ( mat[x][i]>mat[x][y] ) return true;
	return false;
}

bool Col( int x , int y )
{
	rp( i,1,n ) if ( mat[i][y]>mat[x][y] ) return true;
	return false;
}

bool Can()
{
	rp( i,1,n ) rp( j,1,m ) if ( Row( i,j ) && Col( i,j ) ) return false;
	return true;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	cin >> Case ;
	rp( _Case,1,Case )
	{
		cin >> n >> m;
		rp( i,1,n ) rp( j,1,m ) cin >> mat[i][j];
		ok=Can();
		cout << "Case #" << _Case << ": " ;
		if ( ok ) cout << "YES" << endl; else cout << "NO" << endl;
	}
}