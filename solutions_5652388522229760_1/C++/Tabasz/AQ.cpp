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

bool T[11];
int R[1000005], n;

int main()
{
	//ios_base::sync_with_stdio(0);
	for(int i=1; i<=1000000; i++)
	{
		for(int j=0; j<10; j++)
			T[j]=0;
		int tmp=0, j=i;
		while(tmp<10)
		{
			int x=1;
			while(j/x!=0)
			{
				if(!T[(j/x)%10])
				{
					tmp++;
					T[(j/x)%10]=1;
				}
				x*=10;
			}
			if(tmp==10)
				R[i]=j;
			j+=i;
		}
	}
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		if(a==0)
			printf("Case #%d: INSOMNIA\n", i);
		else
			printf("Case #%d: %d\n", i, R[a]);
	}
	return 0;
}
