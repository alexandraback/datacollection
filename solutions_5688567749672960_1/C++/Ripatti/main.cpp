#pragma comment(linker,"/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first
#define MP make_pair

#define FOR(i,k,n) for(int i=(k); i<=(n); i++)
#define DFOR(i,k,n) for(int i=(k); i>=(n); i--)
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a, 0, sizeof(a))

#define LL long long
#define VI  vector<int>
#define PAR pair<int ,int>
#define o_O 1000000000

void __never(int a){printf("\nOPS %d", a);}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();abort();}}

int dp[1000100];
bool F[1000100];
LL Q[1000100];

LL rev( LL i )
{
	char ch[20];
	sprintf( ch, "%lld", i );
	int L = strlen( ch );
	reverse( ch, ch+L );
	LL re;
	sscanf( ch, "%lld", &re );
	return re;
}

void sol()
{
	F[1] = true;
	dp[1] = 1;
	Q[0] = 1;
	int z = 1;

	FOR(a,0,z-1)
	{
		LL c = Q[a];
		LL cc = c+1;
		if (cc<=1000000 && !F[cc])
		{
			dp[cc] = dp[c]+1;
			F[cc] = true;
			Q[z] = cc;
			z++;
		}
		cc = rev(c);
		if (cc<=1000000 && !F[cc])
		{
			dp[cc] = dp[c]+1;
			F[cc] = true;
			Q[z] = cc;
			z++;
		}
	}
}

LL sol2( LL x )
{
	if (x==1) return 1;
	if (x%10==0) return sol2( x-1 )+1;
	if (x<10) return sol2( x-1 )+1;
	//if (x%10>1) return sol2( x-1 )+1;

	char ch[20];
	sprintf( ch, "%lld", x );
	int L = strlen( ch );
	bool flag = true;
	if (x%10!=1) flag = false;
	FOR(i,(L+1)/2,L-2) if (ch[i]!='0') flag = false;
	if (flag)
	{
		LL xx = rev( x );
		if (xx < x-1) return sol2( xx )+1;
		else return sol2( x-1 )+1;
	}

	LL ten = 1;
	FOR(i,(L+1)/2,L-1) ten *= 10;
	LL steps = x%ten-1;
	return sol2( x-steps )+steps;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	sol();

	//FOR(a,1,1000000) if (sol2(a)!=dp[a]) cerr << a << " " << dp[a] << " " << sol2(a) << "\n";

	/*FOR(zz,1,1000)
	{
		cout << zz << "   ";
		FOR(a,1,1000000)
			if (dp[a] == zz)
				cout << a << (dp[a]==dp[a-1]+1 ? "*" : "<") << " ";
		cout << "\n";
	}*/

	//return 0;

	int t=0;
	cin >> t;
	FOR(a,1,t)
	{
		cerr << a << "\n";
		LL x;
		cin >> x;
		cout << "Case #" << a << ": ";
		//cout << dp[x];
		cout << sol2( x ); // << " " << dp[x];
		cout << "\n";
	}
	return 0;
}
