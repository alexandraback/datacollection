#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)

typedef pair<int,int> PII;
typedef pair<double, double> PDD;

//typedef int LL;
typedef __int64 LL;
LL v[10004];
LL E, R;
int n;

struct PLL
{
	LL first, second, at;
	PLL(LL a, LL b, int c)
	{
		first = a;
		second = b;
		at = c;
	}

	PLL()
	{
	}
};

bool operator < (PLL A, PLL B)
{
	if(A.first != B.first)
		return A.first < B.first;

	return A.second > B.second;
}

priority_queue<PLL> Q;
int p[10004];
LL gen[10004];

int Find(int at)
{
	if(at == 0) return 0;
	if(gen[at]) return at;
	return p[at] = Find(at - 1);
}

LL process()
{
	LL ret = 0;
	PLL u;
	LL tospend, extra;
	int i, parent;

	while(!Q.empty())
		Q.pop();

	R = MIN(E, R);
	for(i = 1; i <= n; i++)
	{
		if(i == 1)
			gen[i] = E;
		else
			gen[i] = R;

		p[i] = i;
		
		if(i<n) extra = R;
		else extra = E;

		Q.push( PLL(v[i], E, i) );
		while(extra)
		{
			u = Q.top();
			Q.pop();

			if(u.second == 0)
				continue;

			parent = Find(u.at);
			if(!parent) continue;

			tospend = MIN(gen[parent], extra);
			tospend = MIN(u.second, tospend);

			ret += tospend * u.first;

			extra -= tospend;
			u.second -= tospend;
			gen[parent] -= tospend;

			if(u.second)
				Q.push( u );

			if(!extra)
				break;
		}

	}

	return ret;
}

int main()
{
//	freopen("B-small-attempt2.in", "r", stdin);
//	freopen("temp.out", "w", stdout);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int ks, T;
	LL ans;
	int i;

	scanf("%d", &T);
	for(ks = 1; ks <= T; ks++)
	{
		if(ks==90)
			ks = ks;
		scanf("%I64d %I64d %d", &E, &R, &n);

		for(i = 1; i <= n; i++)
		{
			scanf("%I64d", &v[i]);
		}

		v[n+1] = 0;

		ans = process();

		printf("Case #%d: %I64d\n", ks, ans);
	}

	return 0;
}
