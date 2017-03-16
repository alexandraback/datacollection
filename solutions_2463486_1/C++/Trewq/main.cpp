#include<iostream>
#include<algorithm>
#include<memory.h>
#include<cmath>
using namespace std;
long long fsc[10000001];
bool ispalindrome(long long x)
{
	long long ta=1,tb=1,a,b;
	bool res=1;
	while(10*ta<=x)
		ta*=10;
	while(ta>=tb)
	{
		a=(x/ta)%10;
		b=(x/tb)%10;
		if(a!=b)
		{
			res=0;
			break;
		}
		ta/=10;
		tb*=10;
	}
	return res;
}
int main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int nc;
	cin>>nc;
	long long a,b;
	memset(fsc,0,sizeof(fsc));
	for(long long i=1;i<=10000000;i++)
	{
		if(ispalindrome(i)&&ispalindrome(i*i))
			fsc[i]=1;			
	}
	for(int i=1;i<10000001;i++)
	{
			fsc[i]+=fsc[i-1];
	}
	for(int tc=1;tc<=nc;tc++)
	{
		cin>>a>>b;
		a=sqrt(a-1);
		b=sqrt(b);
		cout<<"Case #"<<tc<<": ";
		cout<<fsc[b]-fsc[a]<<endl;
	}
    return 0;
}                                 