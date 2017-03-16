#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;

int rot(int a)
{
	char s[100];
	sprintf(s,"%d", a);
	int l=strlen(s),i;
	char ch=s[l-1];
	for(i=l-1;i>0;i--)s[i]=s[i-1];
	s[0]=ch;
	while(s[0]=='0')
	{
		ch=s[l-1];
		for(i=l-1;i>0;i--)s[i]=s[i-1];
		s[0]=ch;
	}
	return atoi(s);
}

int main()
{
	int t,c1,c2,n,i,x,a,b;
	map<int , int> mp;
	scanf("%d", &t);
	int g=1;
	while(t--)
	{
		scanf("%d%d", &a,&b);
		int sum1=0;
		mp.clear();
		for(i=a;i<b;i++)
		{
			c1=mp.size();
			if(mp.find(i)==mp.end())
			{
				x=rot(i);
				if(x>=a && x<=b)
				mp[x]=0;
				while(x!=i)
				{
					x=rot(x);
				if(x>=a && x<=b)
					mp[x]=0;
				}
			}
			c2=mp.size();
			n=c2-c1;
			sum1+=(n*(n-1))/2;
		}
		printf("Case #%d: %d\n",g++, sum1);
	}
	return 0;
}
