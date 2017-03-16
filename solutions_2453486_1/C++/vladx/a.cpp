#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdio.h>
#define ZERO(X) memset(X,0,sizeof(X))
#define FOR(I,N) for (I=0;I<(N);++I)
#define REV(I,N) for (I=(N)-1;I>=0;--I)
#define FORK(I,K,N) for (I=(K);I<(N);++I)
#define REVK(I,K,N) for (I=(K);I>=0;--I)
#define pb push_back
#define sci(d) scanf("%d",&d)
#define scll(l) scanf("%lld",&l)
#define scull(l) scanf("%llu",&l)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char b[6][6];
int c[4];

int c2i (char c)
{
	switch (c)
	{
		case '.': return 0;
		case 'X': return 1;
		case 'O': return 2;
		case 'T': return 3;
	}
	return 0;
}

bool chk (int cse)
{
	if (c[1]+c[3]==4)
	{
		printf("Case #%d: X won\n",cse);
		return true;
	}
	if (c[2]+c[3]==4)
	{
		printf("Case #%d: O won\n",cse);
		return true;
	}
	return false;
}

void solve (int cse)
{
	int i,j;
	bool dots=false;
	FOR(i,4)
	{
		ZERO(c);
		FOR(j,4) ++c[c2i(b[i][j])];
		if (chk(cse)) return;
		if (c[0]) dots=true;
	}
	FOR(i,4)
	{
		ZERO(c);
		FOR(j,4) ++c[c2i(b[j][i])];
		if (chk(cse)) return;
		if (c[0]) dots=true;
	}
	ZERO(c);
	FOR(i,4) ++c[c2i(b[i][i])];
	if (chk(cse)) return;
	if (c[0]) dots=true;
	ZERO(c);
	FOR(i,4) ++c[c2i(b[3-i][i])];
	if (chk(cse)) return;
	if (c[0]) dots=true;
	if (dots)
		printf("Case #%d: Game has not completed\n",cse);
	else
		printf("Case #%d: Draw\n",cse);
}

int main ()
{
	int t,i;
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&t);
	FOR(i,t)
	{
		int j;
		FOR(j,4)
		{
			gets(&b[j][0]);
			if (b[j][0]=='\0' || b[j][0]=='\n' || b[j][0]==' ') --j;
		}
		solve(i+1);
	}
	return 0;
}