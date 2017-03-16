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

int d;
int cnt[1010];

void sol()
{ // wrong
	int ans = 1001;
	int divides = 0;
	DFOR(a,1000,2)
		while (cnt[a])
		{
			if (divides > 2000) break;
			ans = min( ans, divides + a );
			cnt[a]--;
			cnt[a/2]++;
			cnt[a-(a/2)]++;
			divides++;
		}
	ans = min( ans, divides + 1 );
	cout << ans;
}

void sol2()
{
	int ans = 1001;
	FOR(a,1,1000)
	{
		int tmp = a;
		FOR(b,a+1,1000) tmp += cnt[b]*((b+a-1)/a-1);
		ans = min( ans, tmp );
	}
	cout << ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t=0;
	cin >> t;
	FOR(a,1,t)
	{
		CLR( cnt );
		cin >> d;
		FOR(b,1,d)
		{
			int tmp;
			cin >> tmp;
			cnt[tmp]++;
		}
		cout << "Case #" << a << ": ";
		sol2();
		//cout << " ";
		//sol();
		cout << "\n";
	}
	return 0;
}
