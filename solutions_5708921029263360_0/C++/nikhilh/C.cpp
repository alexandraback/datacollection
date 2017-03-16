#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	for(int c=1;c<=t;c++)
	{
		int J,P,S,K;

		cin>>J>>P>>S>>K;

		int JP[11][11];
		int JS[11][11];
		int PS[11][11];

		memset(JP,0,sizeof(JP));
		memset(JS,0,sizeof(JS));
		memset(PS,0,sizeof(PS));

		int y = 0;

		for(int j=0;j<J;j++)
		{
			for(int p=0;p<P;p++)
			{
				for(int s=0;s<S;s++)
				{
					if(JS[j][s] < K && JP[j][p] < K && PS[p][s] < K)
					{
						y++;
						JS[j][s]++;
						JP[j][p]++;
						PS[p][s]++;
					}
				}
			}
		}

		printf("Case #%d: %d\n",c,y);

		memset(JP,0,sizeof(JP));
		memset(JS,0,sizeof(JS));
		memset(PS,0,sizeof(PS));

		for(int j=0;j<J;j++)
		{
			for(int p=0;p<P;p++)
			{
				for(int s=0;s<S;s++)
				{
					if(JS[j][s] < K && JP[j][p] < K && PS[p][s] < K)
					{
						printf("%d %d %d\n",j+1,p+1,s+1);
						JS[j][s]++;
						JP[j][p]++;
						PS[p][s]++;
					}
				}
			}
		}
	}
}