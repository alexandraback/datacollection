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
#define PI acos(-1)
#define eps 1e-9
using namespace std;

bool board[50][50],udah[50][50];

int main()
{
	int t;
	scanf("%d",&t);
	FORN(i,t)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int ans = 100;
		FORN(j,(1 << (n*m)))
		{
			int tmp = 0;
			RES(board,false);
			FORN(l,n*m)
				if (j & (1 << l))
				{
					tmp++;
					board[l/m][l%m] = true;
				}
			if (tmp >= k)
				ans = min(ans,tmp);
			if (tmp < ans)
			{
				int z = 0;
				FORN(a,n)
					FORN(b,m)
						if (board[a][b])
							z++;
						else
						{
							bool bisa = false;
							queue<int> qx,qy;
							RES(udah,false);
							udah[a][b] = true;
							qx.push(a);
							qy.push(b);
							while (qx.sz())
							{
								int x = qx.front();
								int y = qy.front();
								qx.pop();
								qy.pop();
								if ((x == 0) || (x == n-1) || (y == 0) || (y == m-1))
								{
									bisa = true;
									break;
								}
								FORS(sumx,-1,1)
									FORS(sumy,-1,1)
										if ((sumx == 0) ^ (sumy == 0))
											if ((x+sumx >= 0) && (x+sumx < n) && (y+sumy >= 0) && (y+sumy < m))
												if (!board[x+sumx][y+sumy] && !udah[x+sumx][y+sumy])
												{
													udah[x+sumx][y+sumy] = true;
													qx.push(x+sumx);
													qy.push(y+sumy);
												}
							}
							if (!bisa)
								z++;
						}
				if (z >= k)
					ans = tmp;
			}
		}
		printf("Case #%d: %d\n",i+1,ans);
	}
}
