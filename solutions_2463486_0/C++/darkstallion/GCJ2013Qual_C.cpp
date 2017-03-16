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

bool isPalindrom(LL i)
{
	string s1,s2;
	while (i > 0)
	{
		s1 += (char)((i%10)+48);
		s2 = (char)((i%10)+48) + s2;
		i /= 10;
	}
	if (s1 == s2)
		return true;
	return false;
}

int main()
{
	vector<int> arr;
	FOR(i,1,10000)
	{
		int x = i;
		vector<int> bil;
		while (x > 0)
		{
			bil.pb(x%10);
			x /= 10;
		}
		x = i;
		FOR(j,1,bil.sz())
		{
			x *= 10;
			x += bil[j];
		}
		if (isPalindrom(x) && isPalindrom((LL)x*(LL)x))
			arr.pb(x);
		if (i < 1000)
		{
			x = i;
			FORN(j,bil.sz())
			{
				x *= 10;
				x += bil[j];
			}
			if (isPalindrom(x) && isPalindrom((LL)x*(LL)x))
				arr.pb(x);
		}
	}
	sort(arr.begin(),arr.end());
	int t;
	scanf("%d",&t);
	FORN(i,t)
	{
		LL a,b;
		int x,y,ans = 0;
		scanf("%lld %lld",&a,&b);
		x = (int)sqrt(a);
		y = (int)sqrt(b);
		if ((LL)x*(LL)x == a)
			x--;
		FORN(j,arr.sz())
			if ((arr[j] > x) && (arr[j] <= y))
				ans++;
		printf("Case #%d: %d\n",i+1,ans);
	}
}
