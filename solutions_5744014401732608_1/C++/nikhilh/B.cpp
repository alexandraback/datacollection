#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	for(int c=1;c<=t;c++)
	{
		printf("Case #%d: ",c);

		long long int b,m,x; //BMX

		cin>>b>>m;

		x = (1ll)<<(b-2);

		if(m <= x)
		{
			printf("POSSIBLE\n");
			int A[b][b];
			memset(A,0,sizeof(A));

			for(int i=0;i<b;i++)
				for(int j=i+1;j<b;j++)
					A[i][j] = 1;

			long long int d = x - m;

			for(int i=1;i<b;i++)
			{
				A[i][b-1] ^= d%2;
				d /= 2;
			}			

			for(int i=0;i<b;i++)
			{
				for(int j=0;j<b;j++)
					cout<<A[i][j];
				printf("\n");
			}						
		}
		else
			printf("IMPOSSIBLE\n");
	}
}