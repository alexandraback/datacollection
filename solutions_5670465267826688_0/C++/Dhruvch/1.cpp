#include<iostream>
#include<cstdio>
using namespace std;
int l,x;
char s[10005];
int mul[8][8]={0,1,2,3,4,5,6,7,1,4,3,6,5,0,7,2,2,7,4,1,6,3,0,5,3,2,5,4,7,6,1,0,4,5,6,7,0,1,2,3,5,0,7,2,1,4,3,6,6,3,0,5,2,7,4,1,7,6,1,0,3,2,5,4};
int prefix[10005];
int suffix[10005];
int power(int a,int b)
{
	int ret=0;
	while(b)
	{
		if(b&1)
			ret=mul[ret][a];
		a=mul[a][a];
		b>>=1;
	}
	return ret;
}
int mapf(char c)
{
	switch(c)
	{
	case '1':
		return 0;
	case 'i':
		return 1;
	case 'j':
		return 2;
	case 'k':
		return 3;
	}
}
bool solve()
{
	if(power(prefix[l-1],x)!=4)
		return false;
	int st=-1;
	for(int i=0;i<l;i++)
	{
		int t=0;
		int sum=mul[suffix[i+1]][prefix[i]];
		if(i==l-1)
			sum=prefix[l-1];
		for(int j=0;j<8;j++)
		{
			if(mul[prefix[i]][t]==1)
			{
				if(st==-1)
					st=i+l*j;
				else
					st=min(st,i+l*j);
			}
			t=mul[t][sum];
		}
	}
	int end=-1;
	for(int i=l,z=0-1;i>=0;i--,z++)
	{
		int t=0;
		int sum=0;
		if(i!=0)
			sum=mul[suffix[i]][prefix[i-1]];
		else
			sum=prefix[l-1];
		for(int j=0;j<8;j++)
		{
			if(mul[t][suffix[i]]==3)
			{
				if(end==-1)
					end=l*x-l*j-1-z;
				else
					end=max(end,l*x-l*j-1-z);
			}
			t=mul[sum][t];
		}
	}
	long long lim=(long long)l*(long long)x;
	if(st>=0&&st<lim&&end>=0&&end<lim&&st<end)
		return true;
	return false;
}
int main()
{
	freopen ("input.in","r",stdin);
	freopen ("output.txt","w",stdout);
	int t;
	cin>>t;
	int k=0;
	while(t--)
	{
		k++;
		cin>>l>>x;
		cin>>s;
		memset(prefix,0,sizeof(prefix));
		memset(suffix,0,sizeof(suffix));
		prefix[0]=mapf(s[0]);
		for(int i=1;i<l;i++)
		{
			prefix[i]=mul[prefix[i-1]][mapf(s[i])];
		}
		suffix[l-1]=mapf(s[l-1]);
		for(int i=l-2;i>=0;i--)
		{
			suffix[i]=mul[mapf(s[i])][suffix[i+1]];
		}
		cout<<"Case #"<<k<<": ";
		if(solve())
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}