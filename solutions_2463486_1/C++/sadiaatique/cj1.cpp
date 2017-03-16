#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;


vector<ll>r,sq,v;


bool ifpal(ll i)
{
	
	int ar[20];
	
	ll b,a,c;
	b=i;
	
	c=0;
	
	while(1)
	{
		if(!b) break;
		ar[c++]=b%10;
		b=b/10;
	}
	
	for(a=0;a<c;a++) if(ar[a]!=ar[c-1-a]) return false;
	return true;
}

int main()
{
	//freopen("0.in","r",stdin);
	//freopen("/home/fahimzubaer/Desktop/C-large-1.in","r",stdin);
	//freopen("/home/fahimzubaer/Desktop/0.out","w",stdout);
	//freopen("0.out","w",stdout);
	
	int t;
	
	scanf("%d",&t);
	
	ll a,b,c,d;
	
	for(a=1;a<=10000000;a++)
	{
		if(ifpal(a))
		{
			if(ifpal(a*a))
			{
				//cout<<a<<" "<<a*a<<endl;
				v.push_back(a*a);
			}
		}
	}
	
	for(int i=1;i<=t;i++)
	{
		cin>>c>>d;
		
		b=0;
		
		for(a=0;a<v.size();a++) if(v[a]>=c && v[a]<=d) b++;
		printf("Case #%d: %lld\n",i,b);
	}
	return 0;
}
