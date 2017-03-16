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

void sol( vector< VI > v )
{
	set< int > Set;
	FA(a,v) FA(b,v[a])
		if (Set.find( v[a][b] ) == Set.end())
			Set.insert( v[a][b] );
		else Set.erase( v[a][b] );
	for ( set< int >::iterator it = Set.begin(); it != Set.end(); it++ )
		cout << " " << (*it);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	FOR(z,1,T)
	{
		int n;
		cin >> n;
		vector< VI > v;
		FOR(a,1,n+n-1)
		{
			VI vv;
			int x;
			FOR(b,1,n)
			{
				cin >> x;
				vv.push_back( x );
			}
			v.push_back( vv );
		}

		cout << "Case #" << z << ":";
		sol( v );
		cout << "\n";
	}
	return 0;
}
