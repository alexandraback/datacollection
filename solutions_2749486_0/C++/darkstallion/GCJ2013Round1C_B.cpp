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
		int x,y;
		scanf("%d%d",&x,&y);
		string ans = "";
		int n = 1;
		int tmpx = 0, tmpy = 0;
		if (abs(x) < abs(y))
		{
			if (y > 0)
			{
				while (n < abs(x))
				{
					if (n % 2)
					{
						ans += 'S';
						tmpy -= n;
					}
					else
					{
						ans += 'N';
						tmpy += n;
					}
					n++;
				}
				if (n == abs(x))
				{
					if (x > 0)
					{
						ans += 'E';
						tmpx += n;
					}
					else
					{
						ans += 'W';
						tmpx -= n;
					}
					n++;
					while ((tmpx != x) || (tmpy != y))
					{
						if (n % 2)
						{
							ans += 'N';
							tmpy += n;
						}
						else
						{
							ans += 'S';
							tmpy -= n;
						}
						n++;
					}
				}
				else
				{
					while ((tmpx != x) || (tmpy != y))
					{
						if (n % 2)
						{
							ans += 'S';
							tmpy -= n;
						}
						else
						{
							ans += 'N';
							tmpy += n;
						}
						n++;
					}
				}
			}
			else
			{
				while (n < abs(x))
				{
					if (n % 2)
					{
						ans += 'N';
						tmpy += n;
					}
					else
					{
						ans += 'S';
						tmpy -= n;
					}
					n++;
				}
				if (n == abs(x))
				{
					if (x > 0)
					{
						ans += 'E';
						tmpx += n;
					}
					else
					{
						ans += 'W';
						tmpx -= n;
					}
					n++;
					while ((tmpx != x) || (tmpy != y))
					{
						if (n % 2)
						{
							ans += 'S';
							tmpy -= n;
						}
						else
						{
							ans += 'N';
							tmpy += n;
						}
						n++;
					}
				}
				else
				{
					while ((tmpx != x) || (tmpy != y))
					{
						if (n % 2)
						{
							ans += 'N';
							tmpy += n;
						}
						else
						{
							ans += 'S';
							tmpy -= n;
						}
						n++;
					}
				}
			}
		}
		else
		{
			if (x > 0)
			{
				while (n < abs(y))
				{
					if (n % 2)
					{
						ans += 'W';
						tmpx -= n;
					}
					else
					{
						ans += 'E';
						tmpx += n;
					}
					n++;
				}
				if (n == abs(y))
				{
					if (y > 0)
					{
						ans += 'N';
						tmpy += n;
					}
					else
					{
						ans += 'S';
						tmpy -= n;
					}
					n++;
					while ((tmpx != x) || (tmpy != y))
					{
						if (n % 2)
						{
							ans += 'E';
							tmpx += n;
						}
						else
						{
							ans += 'W';
							tmpx -= n;
						}
						n++;
					}
				}
				else
				{
					while ((tmpx != x) || (tmpy != y))
					{
						if (n % 2)
						{
							ans += 'W';
							tmpx -= n;
						}
						else
						{
							ans += 'E';
							tmpx += n;
						}
						n++;
					}
				}
			}
			else
			{
				while (n < abs(y))
				{
					if (n % 2)
					{
						ans += 'E';
						tmpx += n;
					}
					else
					{
						ans += 'W';
						tmpx -= n;
					}
					n++;
				}
				if (n == abs(y))
				{
					if (y > 0)
					{
						ans += 'N';
						tmpy += n;
					}
					else
					{
						ans += 'S';
						tmpy -= n;
					}
					n++;
					while ((tmpx != x) || (tmpy != y))
					{
						if (n % 2)
						{
							ans += 'W';
							tmpx -= n;
						}
						else
						{
							ans += 'E';
							tmpx += n;
						}
						n++;
					}
				}
				else
				{
					while ((tmpx != x) || (tmpy != y))
					{
						if (n % 2)
						{
							ans += 'E';
							tmpx += n;
						}
						else
						{
							ans += 'W';
							tmpx -= n;
						}
						n++;
					}
				}
			}
		}
		printf("Case #%d: %s\n",i+1,ans.c_str());
	}
}
