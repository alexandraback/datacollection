#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
long long pw[50];
void pwrs()
{
	long  long int i = 1,j;
	pw[0] = i; 
	for(j=1;j<=44;j++)
	{
		i *= 2;
	   pw[j] = i;
	}
}
long long gcd(long long a,long long b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("bpranv.txt","w",stdout);	
	int t,i,j,k,tt;
	long long w,q,p;
	cin>>t;
	pwrs();
	char c;
	for(tt=1;tt<=t;t++)
	{
		scanf("%lld %c %lld",&p,&c,&q);
		w= gcd(q,p);
		p/=w;
		q/=w;
		
		if(binary_search(pw,pw+41,q))
		{
			j = 1;
			bool o = true;
			if(p>q)
			{
				cout<<"Case #"<<tt<<": impossible\n";
				o = false;
			}
			while(j<=40 && o)
			{
				if(p>=q/2)
				{
					cout<<"Case #"<<tt<<": "<<j<<endl;
					o = false;
				}
				q/= 2;
				j++;
			}
			if(o)
			cout<<"Case #"<<tt<<": impossible\n";
		}
		else
		cout<<"Case #"<<tt<<": impossible\n";
		
		
	}
}
