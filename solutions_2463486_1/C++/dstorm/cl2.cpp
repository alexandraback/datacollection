#include<iostream>
#include<math.h>
#include<vector>
#define N 10000001
using namespace std;
int ispalin(long long int);
int main()
{	int i=1,t,n=0;
	vector<int> list;
	vector<int>::iterator it;
	long long int a,b,cnt,j,sqr;
	cin>>t;
	for(j=1;j<=N;j++)
	{	if(ispalin(j) && ispalin(j*j))
			list.push_back(j);
	}
	while(i<=t)
	{	cin>>a>>b;
		cnt=0;
		for(it=list.begin();it != list.end();it++)
		{	sqr=(long long int)*it * *it;
			if(sqr>=a && sqr<=b)
				cnt++;
		}
		cout<<"Case #"<<i<<": "<<cnt<<endl;
		i++;
	}
	return 0;
}
int ispalin(long long int n)
{	long long int m,rev=0,num;
	num=n;
	while(n)
	{	m=n%10;
		rev=rev*10+m;
		n/=10;
	}
	return rev==num;
}