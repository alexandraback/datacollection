/*
GOOGLE CODEJAM 2014
ROUND 1C
prob: A
id: i.amlansaha@gmail.com
lang: C++
date: May 11, 2014
algo: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long LLU;
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef map<int, int> MAPII;
typedef map<string,int> MAPSI;

#define FOR(i,a,b) for(i=a;i<=b;i++)
#define ROF(i,a,b) for(i=a;i>=b;i--)
#define FR(i,n)	for(i=0;i<n;i++)
#define RF(i,n) for(i=n;i>0;i--)
#define CLR(a) memset ( a, 0, sizeof ( a ) )
#define RESET(a) memset ( a, -1, sizeof ( a ) )
#define PB(a)	push_back ( a )

LL gcd(LL a, LL b)
{
	if ( a%b == 0 )	return b;
	return gcd(b, a%b);
}


int main ()
{
//	freopen("A-small.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A-output.out", "w", stdout);

    int i, j, k, l, temp, t, n, ans, caseno = 0;
    LL p, q, r, s;
    string str;
    scanf ( "%d", &t );
    
    while ( t-- )	{
    	scanf ( "%lld%*c%lld", &p, &q );
    	LL g = gcd(p,q);
    	p/= g;
    	q/= g;
    	ans = 0;
    	printf ( "Case #%d: ", ++caseno );
    	r = q;
    	while ( r > 1)	{
    		if ( r%2 )	{
    			printf ( "impossible\n");
				ans = -1;
				break;
    		}
    		r/= 2;
    	}
    	if ( ans == -1 )	continue;
    	while ( p/q < 1 )	{
    		ans++;
    		q/= 2;
    	}
    	printf ( "%d\n", ans );
    }
    return 0;
}
