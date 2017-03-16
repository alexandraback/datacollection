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

const int mn=110;
const int mm=10010;

int Case;
LL  a,b;
int s[10000001];

bool huiwen( LL x )
{
	LL temp=x;
	LL y=0;
	while ( temp ) y=y*10+temp%10 , temp/=10;
	if ( x==y ) return true; else return false;
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	cin >> Case ; 
	s[0]=0;
	rp( i,1,10000000 ) if ( huiwen( i ) && huiwen( (LL)i*i ) ) s[i]=s[i-1]+1; else s[i]=s[i-1];
	rp( _Case,1,Case )
	{
		cin >> a >> b;
		int x=ceil(sqrt((double)a)) , y=floor(sqrt((double)b));
		cout << "Case #" << _Case << ": " ;
		cout << s[y]-s[x-1] << endl;
	}
}