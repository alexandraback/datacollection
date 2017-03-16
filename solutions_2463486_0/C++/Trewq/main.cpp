#include<iostream>
#include<algorithm>
#include<memory.h>
#include<stack>
using namespace std;
bool ispalindrome(int x)
{
	int ta=1,tb=1,a,b;
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
	int a,b;
	bool fs[1001];
	int fsc[1001];
	fsc[0]=0;
	memset(fs,0,sizeof(fs));
	for(int i=1;i*i<=1000;i++)
	{
		if(ispalindrome(i)&&ispalindrome(i*i))
			fs[i*i]=1;			
	}
	for(int i=1;i<1001;i++)
	{
		if(fs[i])
			fsc[i]=fsc[i-1]+1;
		else
			fsc[i]=fsc[i-1];
	}
	for(int tc=1;tc<=nc;tc++)
	{
		cin>>a>>b;
		cout<<"Case #"<<tc<<": ";
		cout<<fsc[b]-fsc[a-1]<<endl;
	}
    return 0;
}                                 