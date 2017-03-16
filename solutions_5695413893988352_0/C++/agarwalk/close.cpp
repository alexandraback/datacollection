#include<bits/stdc++.h>

#define pb(x) push_back(x);
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);
#define inf 1<<30
#define mod 1000000007
#define ll long long   

using namespace std;

typedef pair<int,int> pii;

int abso(int a,int b)
{
	if(a<b)
		return b-a;
	else
		return a-b;
}

ll power(ll x,ll e)
{
	ll temp;
	if(e==0)
		return 1;
	if(e%2==0)
	{
		temp=power(x,e/2);
		return temp*temp;
	}
	else
	{
		temp=power(x,e/2);
		return temp*temp*x;
	}
}

bool cmp(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y)
{
	if(x.first.first==y.first.first)
	{
		if(x.first.second==y.first.second)
			return x.second<y.second;
		else
			return x.first.second>y.first.second;
	}
	return x.first.first>y.first.first;
}

bool cmp1(pii x,pii y)
{
	if(x.second==y.second)
		return x.first<y.first;
	return x.second<y.second;
}

string cans,jans;
int tans;

void solve(string c,string j,int ind,int len)
{
	//cout<<c<<" "<<j<<" "<<ind<<endl;
	if(ind==len)
	{
		ll temp1=0,temp2=0,temp;
		for(int i=0;i<len;i++)
		{
			temp1=temp1*10+(c[i]-'0');
			temp2=temp2*10+(j[i]-'0');
		}
		if(temp1<temp2)
			temp = temp2-temp1;
		else
			temp = temp1-temp2;
		if(tans==-1||temp<tans)
		{
			tans = temp;
			cans=c;
			jans=j;
		}
		return ;
	}
	if(c[ind]=='?'&&j[ind]=='?')
	{
		for(int i=0;i<=9;i++)
		{
			for(int k=0;k<=9;k++)
			{
				c[ind]=i+'0';
				j[ind]=k+'0';
				solve(c,j,ind+1,len);
			}
		}
	}
	else if(c[ind]=='?'&&j[ind]!='?')
	{
		for(int i=0;i<=9;i++)
		{
			c[ind]=i+'0';
			solve(c,j,ind+1,len);
		}
	}
	else if(c[ind]!='?'&&j[ind]=='?')
	{
		for(int i=0;i<=9;i++)
		{
			j[ind]=i+'0';
			solve(c,j,ind+1,len);
		}
	}
	else
	{
		solve(c,j,ind+1,len);
	}	
}

int main()
{
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cout<<"Case #"<<k<<": ";
		//diff=0;
		string c,j;
		tans=-1;
		cin>>c>>j;
		//cout<<c<<" "<<j<<endl;
		int n=c.size();
		//tans=dif;
		solve(c,j,0,n);
		cout<<cans<<" "<<jans<<endl;
	}
	return 0;
}
