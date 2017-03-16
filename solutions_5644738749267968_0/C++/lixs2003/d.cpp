#include<iostream>
#include<string.h>
#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

int n1,i1,tot,tot1,i,j,n;
double a[1010],b[1010];

int main()
{
	cin>>n1;
	for(i1=1;i1<=n1;i1++)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>a[i];
		for(i=1;i<=n;i++)
			cin>>b[i];
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		j=1;tot=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]>b[j])
			{
				tot++;
				j++;
			}
		}
		j=1;tot1=0;
		for(i=1;i<=n;i++)
		{
			while (j<=n&&b[j]<a[i])
			{
				j++;
			}
			if(j<=n)
			{
				tot1++;
				j++;
			}
		}
		
		cout<<"Case #"<<i1<<": "<<tot<<" "<<n-tot1<<endl;
	}
}
