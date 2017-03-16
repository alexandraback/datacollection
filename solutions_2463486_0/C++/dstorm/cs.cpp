#include<iostream>
#include<math.h>
#define N 100
using namespace std;
int sqroot(int);
int ispalin(int);
int main()
{	int i=1,t,a,b,cnt,j,root;
	cin>>t;
	while(i<=t)
	{	cin>>a>>b;
		cnt=0;
		for(j=a;j<=b;j++)
		{	if(ispalin(j))
			{	root=sqroot(j);
				if(root && ispalin(root))
					cnt++;
			}
		}
		cout<<"Case #"<<i<<": "<<cnt<<endl;;
		i++;
	}
	return 0;
}
int sqroot(int n)
{	int low=0,high=n;
	while(high>=low)
	{	int mid=(low+high)/2;
		int sqr=mid*mid;
		if(sqr==n)
			return mid;
		if(sqr>n)
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;
}
int ispalin(int n)
{	int m,rev=0,num;
	num=n;
	while(n)
	{	m=n%10;
		rev=rev*10+m;
		n/=10;
	}
	return rev==num;
}