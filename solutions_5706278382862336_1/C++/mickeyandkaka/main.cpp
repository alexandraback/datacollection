#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define PB push_back
#define MP make_pair
#define clr(a,b)	(memset(a,b,sizeof(a)))
#define rep(i,a)	for(int i=0; i<(int)a.size(); i++)

const int INF = 0x3f3f3f3f;
const double eps = 1E-8;

LL gcd(LL a, LL b)
{
	return b?gcd(b,a%b):a;
}

int dfs(LL p, LL q)
{
	if(p == q)
		return 0;

	if(p == 1 && q != 1)
		return dfs(1, q/2) + 1;

	q /= 2;
	int ta, tb;
	for(int i=1; i<p; i++)
	{
		if(i > q || p-i > q)
			continue;
		else
		{
			ta = i;
			tb = p - i;
			break;
		}
	}

	LL v = max(ta, tb);

	LL d = gcd(v, q);
	v /= d;
	q /= d;

	return dfs(v, q) + 1;
}

int T;

int main()
{
//	freopen("D:\\in.txt","r",stdin);
	freopen("D:\\A-large.in","r",stdin);
	freopen("D:\\out.txt","w",stdout);

	scanf("%d",&T);
	int cas = 1;
	while(T--)
	{
		LL p,q;
		scanf("%I64d/%I64d",&p, &q);
		LL d = gcd(p, q);
		p /= d;
		q /= d;

		if( (q&(q-1)) != 0)
		{
			printf("Case #%d: impossible\n",cas++);
		}
		else
		{
			int ans = dfs(p, q);
			printf("Case #%d: %d\n",cas++, ans);
		}
	}

	return 0;
}
