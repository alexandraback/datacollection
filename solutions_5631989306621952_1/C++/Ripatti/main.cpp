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

string sol( string s )
{
	string re = s;
	int n = SZ(s);
	FOR(a,0,(1<<(n-1))-1)
	{
		string tmp;
		tmp.push_back( s[0] );
		FOR(b,0,n-2)
			if ((a>>b)&1)
				tmp.push_back( s[b+1] );
			else
				tmp = string( 1, s[b+1] ) + tmp;
		re = max( re, tmp );
	}
	return re;
}

string sol2( string s )
{
	string re;
	FA(a,s)
	{
		string x = string( 1, s[a] );
		re = max( re+x, x+re );
	}
	return re;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	FOR(z,1,T)
	{
		string s;
		cin >> s;
		cout << "Case #" << z << ": ";
		//string s0 = sol(s);
		string s1 = sol2(s);
		//ass( s0==s1 );
		cout << s1;
		cout << "\n";
	}
	return 0;
}
