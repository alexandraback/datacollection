#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

struct tribe
{
	int d, n, w, e, s, dd, dp, ds;
}tr[1001];
int n;

int wall[6000000];

bool atk(int a, int b, int s, bool inc)
{
	a += 3000000;
	b += 3000000;
	b--;
	bool ret = false;
	for(int i = a ; i <= b ; i++)
	{
		if(wall[i] < s)
		{
			ret = true;
			if(inc) wall[i] = s;
		}
	}
	return ret;
}

int calc()
{
	int sum = 0;
	memset(wall, 0, sizeof(wall));
	int day = 0;
	while(1)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			if(tr[i].n && tr[i].d == day)
			{
				if(atk(tr[i].w, tr[i].e, tr[i].s, false)) sum++;
			}
		}
		for(int i = 1 ; i <= n ; i++)
		{
			if(tr[i].n && tr[i].d == day)
			{
				atk(tr[i].w, tr[i].e, tr[i].s, true);
				tr[i].d += tr[i].dd;
				tr[i].n--;
				tr[i].w += tr[i].dp;
				tr[i].e += tr[i].dp;
				tr[i].s += tr[i].ds;
			}
		}
		int k = 0;
		for(int i = 1 ; i <= n ; i++)
			if(tr[i].n) k++;
		if(k == 0) break;
		
		day++;
	}
	return sum;
}

int main()
{
	int T;
	freopen("C.in","r", stdin);
	freopen("C.out", "w",stdout);
	cin >> T;
	for(int tt = 1 ; tt <= T ; tt++)
	{
		cin >> n;
		for(int i = 1 ; i <= n ; i++)
			cin >> tr[i].d >> tr[i].n >> tr[i].w>> tr[i].e>> tr[i].s>> tr[i].dd>> tr[i].dp>> tr[i].ds;
		cout << "Case #" << tt << ": " << calc() << endl;
	}
	return 0;
}
