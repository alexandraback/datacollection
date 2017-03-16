#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int lli;

int main(void)
{
	lli t;
	scanf("%lld", &t);
	for(lli tt = 1;tt <= t;tt++) {
	printf("Case #%lld: ", tt);
	lli b, m;
	scanf("%lld%lld", &b, &m);
	if(m > lli(1ll<<(b-2)))
	{
		cout << "IMPOSSIBLE\n";
		continue;
	}
	m = lli(1ll<<(b-2))-m;

	vector<vector<lli>> edge(b+1, vector<lli>(b+1, 0));

	for(lli i = 1;i <= b;i++)
	{
		for(lli j = i+1;j <= b;j++) edge[i][j] = 1;
	}
	
	for(lli i = 2;i < b;i++)
	{
		if(m >= 1ll<<(b-i-1))
		{
			m -= 1ll<<(b-i-1);
			edge[1][i] = 0;
		}
	}

	printf("POSSIBLE\n");
	for(lli i = 1;i <= b;i++)
	{
		for(lli j = 1;j <= b;j++) printf("%lld", edge[i][j]);
		printf("\n");
	} }
}