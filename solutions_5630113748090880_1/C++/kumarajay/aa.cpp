#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin >>t;
	int n,x;
	int a[2504];
	int b[2504];
	for(int i=1;i<=t;i++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(a));
		cin >>n;
		for(int j=0;j<(2*n-1)*n;j++)
		{
			cin >>x;
			a[x]++;
		}
		int kk=0;
		for(int k=1;k<=2500;k++)
		{
		if(a[k]%2!=0&&a[k]!=0)
		{
			b[kk]=k;
			kk++;
		}
		}
		sort(b,b+kk);
		int kkk=0;
		cout<<"Case #"<<i<<": ";
		while(b[kkk]!=0)
		{
			cout << b[kkk]<<" ";
			kkk++;
			if(kkk==2501)
				break;
		}
		cout <<endl;
	}
	
				






	
		
}
