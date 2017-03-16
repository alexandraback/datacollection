#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int j1=1;j1<=t;j1++)
	{
		int n;
		cin>>n;
		float a[1002]={},b[1002]={};
		for(int i=0;i<n;i++)
			scanf("%f",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%f",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		int a1=0,a2=0;
		int k=0;
		for(int i=0;i<n;i++)
		{
			for(;k<n;k++)
				if(a[k]>b[i])
				{
					a1++;
					k++;
					break;
				}
		}
		k=0;
		for(int i=0;i<n;i++)
		{
			for(;k<n;k++)
				if(b[k]>a[i])
				{
					a2++;
					k++;
					break;
				}
		}
		printf("Case #%d: %d %d\n",j1,a1,n-a2);
	}
	return 0;
}




