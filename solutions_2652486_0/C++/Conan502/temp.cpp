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

const int mn=20;

int Case;
int T,N,M,K;
int v[mn];

void work2()
{
	rp( x1,2,M ) rp( x2,2,M )
	{
		int temp=0;
		rp( j,1,K ) if ( v[j]==x1 || v[j]==x2 || v[j]==x1*x2 || v[j]==1 ) ++temp;
		if ( temp==K )
		{
			cout << x1 << x2 << endl;
			return ;
		}
	}
}

void work3()
{
	rp( x1,2,M ) rp( x2,2,M ) rp( x3,2,M )
	{
		int temp=0;
		rp( j,1,K ) if ( v[j]==x1 || v[j]==x2 || v[j]==x1*x2 || v[j]==1 || v[j]==x3 || v[j]==x3*x1 || v[j]==x3*x2 || v[j]==x1*x2*x3 ) ++temp;
		if ( temp==K )
		{
			cout << x1 << x2 << x3 << endl;
			return ;
		}
	}
}

int main()
{
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("C-small-1-attempt0.out","w",stdout);
	cin >> Case;
	rp( Casei,1,Case )
	{
		cout << "Case #" << Casei << ": " << endl;
		cin >> T >> N >> M >> K ;
		rp( Ti,1,T )
		{
			rp( i,1,K ) cin >> v[i];
			if ( N==1 ) 
			{
				rp( i,2,M )
				{
					int temp=0;
					rp( j,1,K ) if ( v[j]==i || v[j]==1 ) ++temp;
					if ( temp==K )
					{
						cout << i << endl;
						break;
					}
				}
			}
			if ( N==2 )
			{
				work2();
			}
			if ( N==3 )
			{
				work3();
			}
		}
	}
}