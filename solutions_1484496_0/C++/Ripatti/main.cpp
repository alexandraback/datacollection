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

int n;
int p[32];

void sol()
{
	FOR(a,1,(1<<n)-1)
	{
		int sum1 = 0;
		FOR(b,0,n-1) if ((a>>b)&1) sum1 += p[b];
		int z = (1<<n)-1-a;
		for (int b=z; b; b=(b-1)&z)
		{
			int sum2 = 0;
			FOR(c,0,n-1) if ((b>>c)&1) sum2 += p[c];
			if (sum1==sum2)
			{
				FOR(c,0,n-1) if ((a>>c)&1) cout << p[c] << " ";
				cout << "\n";
				FOR(c,0,n-1) if ((b>>c)&1) cout << p[c] << " ";
				cout << "\n";
				return;
			}
		}
	}

	cout << "Impossible\n";
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	FOR(a,1,T)
	{
		cin >> n;
		FOR(b,0,n-1) cin >> p[b];
		cout << "Case #" << a << ":\n";
		sol();
	}
	return 0;
}
