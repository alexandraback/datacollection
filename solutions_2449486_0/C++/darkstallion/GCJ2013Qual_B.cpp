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
		int n,m;
		scanf("%d%d",&n,&m);
		int mat[n][m];
		FORN(j,n)
			FORN(k,m)
				scanf("%d",&mat[j][k]);
		bool benar = true;
		FORN(j,n)
			FORN(k,m)
				if (benar)
				{
					bool betul = true;
					FORN(l,m)
						if (mat[j][l] > mat[j][k])
						{
							betul = false;
							break;
						}
					if (betul)
						continue;
					betul = true;
					FORN(l,n)
						if (mat[l][k] > mat[j][k])
						{
							betul = false;
							break;
						}
					if (!betul)
						benar = false;
				}
		if (benar)
			printf("Case #%d: YES\n",i+1);
		else
			printf("Case #%d: NO\n",i+1);
	}
}
