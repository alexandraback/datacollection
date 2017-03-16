#include <bits/stdc++.h>

using namespace std;

int dfs(int * A, int x, int n)
{
	int f = x;
	int l = x;
	int c = 1;

	int V[n];
	memset(V,0,sizeof(V));

	V[x] = 1;

	while(1)
	{
		if(V[A[x]])
		{
			break;
		}
		else
		{
			l = x;
			x = A[x];
			V[x] = 1;
			c++;
		}
	}

	if(A[x] == f)
		return c;
	else if(A[x] == l)
	{
		for(int i=0;i<n;i++)
			if(A[i] == x && V[i] == 0)
				return c+1;
		return c;
	}

	return 0;
}

int main()
{
	int t;
	cin>>t;

	for(int c=1;c<=t;c++)
	{
		int n;
		cin>>n;

		int A[n];

		for(int i=0;i<n;i++)
			cin>>A[i];

		for(int i=0;i<n;i++)
			A[i]--;

		int m = 0;
		for(int i=0;i<n && m<n;i++)
			m = max(m,dfs(A,i,n));

		printf("Case #%d: %d\n",c,m);
	}
}