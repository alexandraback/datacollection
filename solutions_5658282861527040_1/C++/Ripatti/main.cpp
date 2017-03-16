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

int A, B, K;

void sol()
{
	int ans = 0;
	FOR(a,0,A-1)
		FOR(b,0,B-1)
			if ((a&b)<K)
				ans++;
	cout << ans;
}

void sol2()
{
	LL ans = 0;
	A--; B--; K--;
	FOR(a,-1,29) if (a==-1 || ((A>>a)&1))
		FOR(b,-1,29) if (b==-1 || ((B>>b)&1))
			FOR(k,-1,29) if (k==-1 || ((K>>k)&1))
			{
				LL tmp = 1;
				FOR(z,0,29)
				{
					int mia=0, maa=1, mib=0, mab=1, mik=0, mak=1;

					if (z==a) mia=maa=0;
					else if (z>a) mia=maa=((A>>z)&1);

					if (z==b) mib=mab=0;
					else if (z>b) mib=mab=((B>>z)&1);

					if (z==k) mik=mak=0;
					else if (z>k) mik=mak=((K>>z)&1);

					int tt=0;
					FOR(aa,mia,maa)
						FOR(bb,mib,mab)
							FOR(kk,mik,mak)
								if ((aa&bb)==kk)
									tt++;
					tmp*=tt;
				}
				ans += tmp;
			}
	cout << ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	FOR(a,1,t)
	{
		cerr << a << "\n";

		cin >> A >> B >> K;
		
		cout << "Case #" << a << ": ";
		//sol();
		//cout << " ";
		sol2();
		cout << "\n";
	}
	return 0;
}
