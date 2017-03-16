#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

long long gcd(long long a, long long b)
{
	if(a==0)return b;
	else return gcd(b%a,a);
}

long long getnum()
{
	char x=getchar();
	long long ans=0;
	while(x!='/')
	{
		ans*=10;
		ans+=x-'0';
		x=getchar();
	}
	return ans;
}

long long getden()
{
	char x=getchar();
	long long ans=0;
	while(x!='\n')
	{
		ans*=10;
		ans+=x-'0';
		x=getchar();
	}
	return ans;
}

long long power(int x)
{
     long long ans=1;
     for(int i=0;i<x;i++)ans*=2;
     return ans;
}

int main()
{
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	int t;
    int k=1;
    cin>>t;
    char x= getchar();
    for(k=1;k<=t;k++)
    {	
    	long long p,q,r;
    	p=getnum();
    	q=getden();
    	long long g=gcd(p,q);
    	p/=g;
    	q/=g;
    	r=q;
    	int ans=0;
    	while(!(r&1)){r/=2;ans++;}
    	if(r==1){
        long long x=1;
        ans=1;
        long long j=q/2;
        while((j-p*x)>0){ans++;x*=2;}
        
        cout<<"Case #"<<k<<": "<<ans<<"\n";
        }
    	else cout<<"Case #"<<k<<": impossible\n";
    }
return 0;
}
