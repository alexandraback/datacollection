#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

#define st first
#define nd second
#define make(a,b) make_pair(a,b)

typedef pair<int,int> pun;
typedef long long ll;

char slo[N];
int tab[N];

int con(char x)
{
	return x - 'i' + 2;
}

int g[5][5];

int dodaj(int x,int y)
{
	int sign = x/abs(x) * y/abs(y);
	int war = g[abs(x)][abs(y)];
	return war * sign;
}

bool test()
{
	int n;
	ll x;
	scanf("%d%lld",&n,&x);
	scanf("%s",slo);
	for (int i=0;i<n;i++)
		tab[i] = con( slo[i] );
	int l = 0;
	int pre = 1, suf = 1;
	long long p, k;
	for ( p = 0 ; p < 5*n ; p++ )
	{
		pre = dodaj( pre, tab[l] );
		if ( pre == 2 ) break;
		l ++;
		if ( l == n ) l = 0;
	}
	if ( p == 5*n ) return 0;
	l = n-1;
	for ( k = -1; k >= -5*n; k--) 
	{
		suf = dodaj( tab[l], suf );
		if ( suf == 4 ) break;
		l--;
		if ( l == -1 ) l = n-1;
	}
	if ( k == -5*n ) return 0;
	int cale = 1;
	for (int i=0;i<n;i++) cale = dodaj(cale, tab[i]);
//	printf("%lld %lld\n",p,k);
	pre = 1;
	p++;
	while( p < n*x + k )
	{
		if ( p % n == 0 && (p+n) <= n*(ll)x + k )
		{
			ll ile = ( n*(ll)x + k - p)/n;
			int war;
			if ( cale == 1 ) war = 1;
			else if ( cale == -1 )
			{
				if ( ile%2 ) war = -1;
				else war = 1;
			}
			else
			{
				if ( ile%4 == 0 ) war = 1;
				if ( ile%4 == 1 ) war = cale;
				if ( ile%4 == 2 ) war = -1;
				if ( ile%4 == 3 ) war = -cale;
			}
			pre = dodaj( pre, war );
			p += ile*n;
		}
		else
		{
			pre = dodaj( pre, tab[ p%n ] );
			p ++;
		}
	}
	return pre == 3;
}

int main()
{
	int t;
	scanf("%d",&t);
	for (int i=1;i<=4;i++)
		g[1][i] = g[i][1] = i;
	for (int i=2;i<=4;i++)
		g[i][i] = -1;
	for (int i=0;i<3;i++)
		g[ i+2 ][ (i+1)%3+2 ] = 5 - i - (i+1)%3;
	for (int i=0;i<3;i++)
		g[ (i+1)%3+2 ][ i+2 ] = i + (i+1)%3 - 5;
/*	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
			printf("%d%c",g[i][j],j==4?10:32);*/
	for (int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		printf("%s\n",test()? "YES":"NO");
	}
}
