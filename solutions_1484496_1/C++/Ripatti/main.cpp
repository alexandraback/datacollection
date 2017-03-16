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

struct HELEM
{
	LL sum;
	int ord;
	HELEM * next;
};

struct HTABLE
{
	HELEM H[10000000];
	HELEM * hTable[1100000];
	int sz;
	void clear()
	{
		CLR(hTable);
		sz = 0;
	}
	int get_key( LL sum )
	{
		return (int)( (sum*(o_O+7)) & (((LL)1 << 20)-1) );
	}
	HELEM * find( LL sum )
	{
		for (HELEM * h = hTable[get_key(sum)]; h; h = h->next)
			if (h->sum == sum)
				return h;
		return 0;
	}
	void insert( LL sum, int ord )
	{
		HELEM * h = find( sum );
		if (h)
		{
			h->ord = ord;
			return;
		}
		int k = get_key(sum);
		H[sz].sum = sum;
		H[sz].ord = ord;
		H[sz].next = hTable[k];
		hTable[k] = &H[sz];
		sz++;
	}
} Ha;

int n;
LL p[512];
LL order[40002][256];
//map< LL, int > Map;

void sol()
{
	//Map.clear();
	Ha.clear();
	random_shuffle( p+1, p+501 );
	FOR(a,1,40000)
	{
		random_shuffle( p+1, p+251 );
		LL sum = 0;
		FOR(b,1,250)
		{
			sum += p[b];
			//Map[sum] = a;
			Ha.insert( sum, a );
			order[a][b] = p[b];
		}
	}

	cerr << "map is created\n";
	cerr << "size=" << Ha.sz << "\n";

	int ii=1;
	while(1)
	{
		if (ii%1000==0) cerr << "try " << ii << "\n";
		ii++;
		random_shuffle( p+251, p+501 );
		LL sum = 0;
		FOR(b,1,250)
		{
			sum += p[b+250];
			//if (Map.find(sum) != Map.end())
			HELEM * h = Ha.find( sum );
			if ( h )
			{
				FOR(c,1,b) cout << p[c+250] << " ";
				cout << "\n";
				int z = h->ord;
				FOR(c,1,250)
				{
					cout << order[z][c] << " ";
					sum -= order[z][c];
					if (sum==0) break;
				}
				cout << "\n";
				ass( sum==0 );
				return;
			}
		}
	}
}

void gen()
{
	int Z = 100;
	WR("%d\n", Z);
	FOR(a,1,Z)
	{
		WR("500");
		FOR(b,1,500)
		{
			LL tmp = 0;
			tmp = tmp*1000 + rand()%1000;
			tmp = tmp*1000 + rand()%1000;
			tmp = tmp*1000 + rand()%1000;
			tmp = tmp*1000 + rand()%1000;
			cout << " " << tmp;
		}
		cout << "\n";
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	//gen();
	//return 0;

	int T;
	cin >> T;
	FOR(a,1,T)
	{
		cerr << a << " " << clock() << "\n";
		cin >> n;
		FOR(b,1,n) cin >> p[b];
		cout << "Case #" << a << ":\n";
		sol();
	}
	return 0;
}
