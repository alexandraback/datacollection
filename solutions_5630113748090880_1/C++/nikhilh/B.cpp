#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	for(int c=1;c<=t;c++)
	{
		int A[2505];
		memset(A,0,sizeof(A));

		int n;
		cin>>n;

		n = (2*n*n) - n;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			A[x]++;
		}	

		printf("Case #%d:",c);
		for(int i=0;i<2505;i++)
			if(A[i]%2)
				printf(" %d",i);

		printf("\n");
	}
}