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
	FORN(l,t)
	{
		string st;
		int n;
		cin >> st;
		scanf("%d",&n);
		int ans = 0;
		FORN(i,st.sz())
			FOR(j,i,st.sz())
			{
				int tmp = 0;
				FORS(k,i,j)
					if ((st[k] != 'a') && (st[k] != 'i') && (st[k] != 'u') && (st[k] != 'e') && (st[k] != 'o'))
					{
						tmp++;
						if (tmp >= n)
						{
							ans++;
							break;
						}
					}
					else
						tmp = 0;
			}
		printf("Case #%d: %d\n",l+1,ans);
	}
}
