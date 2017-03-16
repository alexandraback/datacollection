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
int A[1100];

int sol()
{
	int re = 0;
	int p[20];
	FOR(a,0,n-1) p[a] = a+1;
	do
	{
		FOR(a,1,n)
		{
			bool flag = true;
			FOR(b,0,a-1)
				if (!(p[(b+1)%a] == A[p[b]] || p[(b+a-1)%a] == A[p[b]]))
					flag = false;
			if (flag) re = max( re, a );
		}
	}
	while (next_permutation( p, p+n ));

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
		cerr << z << "\n";
		cin >> n;
		FOR(a,1,n) cin >> A[a];

		cout << "Case #" << z << ": ";
		int re = sol();
		cout << re;
		cout << "\n";
	}
	return 0;
}
