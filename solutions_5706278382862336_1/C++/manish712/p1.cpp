#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef long long int ll;

ll p,q,g,l,t;
char str[55];

ll gcd(ll a, ll b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}

int main()
{
    cin>>t;
    int tt = 1;
    while(t--)
    {
    	p = 0;
    	q = 0;
    	cin>>str;
    	int i;
    	for(i=0;str[i]!='/';i++)
    	{
    		p = p*10 + (int)(str[i]-'0');
    	}
    	i++;
    	while(str[i]!='\0')
    	{
    		q = q*10 + (int)(str[i]-'0');
    		i++;
    	}
    	g = gcd(p,q);
    	p = p/g;
    	q = q/g;
    	if(	((q-1)&q))
    	{
    		cout<<"Case #"<<tt++<<": impossible\n";
    		continue;
    	}
    	if(p==1)
    	{
    		cout<<"Case #"<<tt++<<": "<<log2(q)<<"\n";
    	}
    	else
    	{
    		ll k = 0;
    		while(q>p)
    		{
    			q = q/2;
    			k++;
    		}
    		cout<<"Case #"<<tt++<<": "<<k<<"\n";
    	}

    }	
}
    