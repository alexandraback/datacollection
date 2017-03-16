#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int A[200];
int N,p,s;
int main()
{
	int T,i,maxi,mini,off,ans;

	scanf("%d",&T);

	for(i=1;i<=T;i++)
	{
		ans=0;
		scanf("%d%d%d",&N,&s,&p);
		for(int j=0;j<N;j++)
			scanf("%d",&A[j]);

		sort(A,A+N);

		for(int j=N-1;j>=0;j--)
		{
			maxi=mini=A[j]/3;
			off=A[j]%3;
			if(off!=0)
				maxi++;
			
			if(maxi>=p)
			{
				ans++;
				continue;
			}

			if(s>0)
			{
				maxi++;
				if(off<=1)
					mini--;

				if(maxi-mini<=2 && mini>=0 && maxi<=10 && maxi>=p)
				{
					ans++;
					s--;
				}
			}
		}

		printf("Case #%d: %d\n",i,ans);
	}



	return 0;
}
