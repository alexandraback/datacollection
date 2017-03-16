//darkstallion's template

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
#define PI 3.1415926535897932384626433832795
#define eps 1e-9
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	FORN(i,t)
	{
		getchar();
		char st[4][4];
		FORN(j,4)
			gets(st[j]);
		bool ktmu = false, finish = true;
		FORN(j,4)
		{
			int x = 0, y = 0, z = 0;
			FORN(k,4)
			{
				if (st[j][k] == 'X')
					x++;
				if (st[j][k] == 'O')
					y++;
				if (st[j][k] == 'T')
					z++;
				if (st[j][k] == '.')
					finish = false;
			}
			if (x + z == 4)
			{
				printf("Case #%d: X won\n",i+1);
				ktmu = true;
				break;
			}
			if (y + z == 4)
			{
				printf("Case #%d: O won\n",i+1);
				ktmu = true;
				break;
			}
		}
		if (!ktmu)
			FORN(k,4)
			{
				int x = 0, y = 0, z = 0;
				FORN(j,4)
				{
					if (st[j][k] == 'X')
						x++;
					if (st[j][k] == 'O')
						y++;
					if (st[j][k] == 'T')
						z++;
					if (st[j][k] == '.')
						finish = false;
				}
				if (x + z == 4)
				{
					printf("Case #%d: X won\n",i+1);
					ktmu = true;
					break;
				}
				if (y + z == 4)
				{
					printf("Case #%d: O won\n",i+1);
					ktmu = true;
					break;
				}
			}
		if (!ktmu)
		{
			int x = 0, y = 0, z = 0;
			FORN(j,4)
			{
				if (st[j][j] == 'X')
					x++;
				if (st[j][j] == 'O')
					y++;
				if (st[j][j] == 'T')
					z++;
				if (st[j][j] == '.')
					finish = false;
			}
			if (x + z == 4)
			{
				printf("Case #%d: X won\n",i+1);
				ktmu = true;
			}
			if (y + z == 4)
			{
				printf("Case #%d: O won\n",i+1);
				ktmu = true;
			}
		}
		if (!ktmu)
		{
			int x = 0, y = 0, z = 0;
			FORN(j,4)
			{
				if (st[j][3-j] == 'X')
					x++;
				if (st[j][3-j] == 'O')
					y++;
				if (st[j][3-j] == 'T')
					z++;
				if (st[j][3-j] == '.')
					finish = false;
			}
			if (x + z == 4)
			{
				printf("Case #%d: X won\n",i+1);
				ktmu = true;
			}
			if (y + z == 4)
			{
				printf("Case #%d: O won\n",i+1);
				ktmu = true;
			}
		}
		if (!ktmu)
		{
			if (finish)
				printf("Case #%d: Draw\n",i+1);
			else
				printf("Case #%d: Game has not completed\n",i+1);
		}
	}
}
