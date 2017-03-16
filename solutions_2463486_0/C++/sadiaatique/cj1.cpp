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
using namespace std;

int bi[1005];
int sq[1005];

bool ifpal(int i)
{
	string s,st;
	int a,b;
	b=i;
	
	s="";
	
	char c;
	
	while(1)
	{
		if(!b) break;
		c=b%10+'0';
		s=s+c;
		b=b/10;
	}
	st=s;
	reverse(st.begin(),st.end());
	if(s==st) return true;
	return false;
}

int main()
{
	//freopen("0.in","r",stdin);
	//freopen("/home/fahimzubaer/Desktop/C-small-attempt0.in","r",stdin);
	//freopen("/home/fahimzubaer/Desktop/0.out","w",stdout);
	
	int t;
	
	scanf("%d",&t);
	
	int a,b,c;
	
	for(a=1;a<=1000;a++)
	{
		if(ifpal(a)) bi[a]=1;
		else bi[a]=0;
	}
	
	for(a=1;a*a<=1000;a++)
	{
		sq[a*a]=a;
	}
	
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b;
		c=0;
		
		for(int j=a;j<=b;j++)
		{
			if(bi[j]==1 && bi[sq[j]]==1) c++;
		}
		
		printf("Case #%d: %d\n",i,c);
	}
	return 0;
}
