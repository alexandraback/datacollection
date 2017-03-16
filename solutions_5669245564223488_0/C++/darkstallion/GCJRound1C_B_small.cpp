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

bool udah[50];
int n;
string s[50];
vector<string> tmp;

int dfs(int i)
{
	if (i == n)
	{
		string st;
		FORN(j,tmp.sz())
			st += tmp[j];
		bool uda[26];
		RES(uda,false);
		uda[(int)st[0]-'a'] = true;
		FORS(j,1,st.sz())
			if ((st[j] != st[j-1]) && uda[(int)st[j]-'a'])
				return 0;
			else
				uda[(int)st[j]-'a'] = true;
		return 1;
	}
	else
	{
		int ans = 0;
		FORN(j,n)
			if (!udah[j])
			{
				udah[j] = true;
				tmp.pb(s[j]);
				ans += dfs(i+1);
				tmp.popb();
				udah[j] = false;
			}
		return ans;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	FORN(i,t)
	{
		scanf("%d",&n);
		FORN(j,n)
			cin >> s[j];
		RES(udah,false);
		tmp.clear();
		printf("Case #%d: %d\n",i+1,dfs(0));
	}
}
