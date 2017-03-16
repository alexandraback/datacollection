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

int n;
char C[105];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%s", C);
		char prev=C[0];
		int ind=1, res=0;
		while((int)C[ind]!=0)
		{
			if(C[ind]!=prev)
				res++;
			prev=C[ind];
			ind++;
		}
		if(prev=='-')
			res++;
		printf("Case #%d: %d\n", i, res);
	}
	return 0;
}
