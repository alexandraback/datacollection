#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int t, k, c, s;
LL len;
vector<LL> V;

void go(int ind)
{
	LL res=0, tmp=1;
	for(int i=0; i<c; i++)
	{
		res+=tmp*ind;
		//printf("%d %d\n", i, res);
		tmp*=k;
		ind++;
		if(ind>=k)
			ind--;
	}
	V.PB(res+1);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &t);
	for(int i=1; i<=t; i++)
	{
		V.clear();
		scanf("%d%d%d", &k, &c, &s);
		len=1;
		for(int j=0; j<c; j++)
			len*=k;
		if(s*c<k)
		{
			printf("Case #%d: IMPOSSIBLE\n", i);
			continue;
		}
		for(int j=0; j<k; j+=c)
			go(j);
		printf("Case #%d: ", i);
		for(int j=0; j<(int)V.size(); j++)
			printf("%lld ", V[j]);
		printf("\n");
	}
	return 0;
}
