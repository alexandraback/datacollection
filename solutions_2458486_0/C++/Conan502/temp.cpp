#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define rp(i,l,r) for ( int i=(int)(l); i<=(int)(r); ++i )
#define dp(i,l,r) for ( int i=(int)(l); i>=(int)(r); --i )

typedef long long LL;

const int mn=210;
const int mm=410;

int Case;
int Key,N,tot;
int num[41];
int open[mn],chest[mn][mm],chest_key[mn];
int pi[mn];
int h[mn];
bool bo[2100000],ok;

void dfs( int sta , int deep )
{
	if ( ok ) return;
	if ( bo[sta] ) return;
	bo[sta]=1;
	if ( sta==pi[N]-1 ) 
	{
		ok=true;
		rp( i,1,N ) cout << " " << h[i] ;
		cout << endl;
		return;
	}
	int Num[41];
	memcpy( Num , num , sizeof num );
	rp( i,1,deep-1 ) rp( j,1,chest_key[h[i]] ) Num[chest[h[i]][j]]++;
	rp( i,1,deep-1 ) Num[open[h[i]]]--;
	if ( ok ) return;
	rp( i,1,N ) if ( (sta & pi[i-1])==0 && Num[open[i]]>0 )
	{
		int temp=(sta|pi[i-1]);
		h[deep]=i;
		dfs( temp , deep+1 );
		h[deep]=0;
		if ( ok ) return ;
	}
}

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	cin >> Case ;
	pi[0]=1;
	rp( i,1,21 ) pi[i]=pi[i-1] << 1;
	rp( _Case,1,Case )
	{
		int x;
		ok=false;
		memset( num , 0 , sizeof num );
		memset( chest , 0 , sizeof chest );
		memset( bo , false , sizeof bo );
		cin >> Key >> N;
		rp( i,1,Key ) cin >> x , ++num[x];
		rp( i,1,N ) 
		{
			cin >> open[i];
			cin >> chest_key[i];
			rp( j,1,chest_key[i] ) cin >> chest[i][j];
		}
		cout << "Case #" << _Case << ":" ;
		dfs( 0 , 1 );
		if ( !ok ) cout << " IMPOSSIBLE" << endl;
	}
}