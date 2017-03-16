#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
	int t,n,a[100][50];
	int itr,i,j;

	cin>>t;
	for(itr=1;itr<=t;itr++)
	{
		int b[2501]={0};
		cin>>n;
		for(i=0;i<2*n-1;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>a[i][j];
				b[a[i][j]]++;
			}
		}
		printf("Case #%d: ",itr);
		for(i=1;i<=2500;i++)
			if(b[i]%2)
				cout<<i<<" ";
		cout<<'\n';
	}

	return 0;
}