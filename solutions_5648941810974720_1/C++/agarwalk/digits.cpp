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

int main()
{
	int t;
	cin>>t;
	int ans[20];
	string str;
	for(int i=1;i<=t;i++)
	{
		map<char,int> mymap;
		memset(ans,0,sizeof ans);
		cin>>str;
		for(int j=0;j<str.size();j++)
			mymap[str[j]]++;
		int temp;
		temp=mymap['Z'];
		ans[0]=temp;
		mymap['Z']-=temp;
		mymap['E']-=temp;
		mymap['R']-=temp;
		mymap['O']-=temp;
		temp = mymap['G'];
		ans[8]=temp;
		mymap['E']-=temp;
		mymap['I']-=temp;
		mymap['H']-=temp;
		mymap['T']-=temp;
		mymap['G']-=temp;
		temp = mymap['W'];
		ans[2]=temp;
		mymap['T']-=temp;
		mymap['O']-=temp;
		mymap['W']-=temp;
		temp = mymap['X'];
		ans[6]=temp;
		mymap['S']-=temp;
		mymap['I']-=temp;
		mymap['X']-=temp;
		temp = mymap['H'];
		ans[3]=temp;
		mymap['T']-=temp;
		mymap['H']-=temp;
		mymap['R']-=temp;
		mymap['E']-=temp;
		mymap['E']-=temp;
		temp = mymap['R'];
		ans[4]=temp;
		mymap['F']-=temp;
		mymap['O']-=temp;
		mymap['U']-=temp;
		mymap['R']-=temp;	
		temp = mymap['F'];
		ans[5]=temp;
		mymap['F']-=temp;
		mymap['I']-=temp;
		mymap['V']-=temp;
		mymap['E']-=temp;
		temp = mymap['V'];
		ans[7]=temp;
		mymap['S']-=temp;
		mymap['E']-=temp;
		mymap['V']-=temp;
		mymap['E']-=temp;
		mymap['N']-=temp;
		temp = mymap['I'];
		ans[9]=temp;
		mymap['N']-=temp;
		mymap['I']-=temp;
		mymap['N']-=temp;
		mymap['E']-=temp;
		temp = mymap['O'];
		ans[1]=temp;
		mymap['O']-=temp;
		mymap['N']-=temp;
		mymap['E']-=temp;
		cout<<"Case #"<<i<<": ";
		for(int j=0;j<=9;j++)
		{
			while(ans[j]!=0)
			{
				cout<<j;
				ans[j]--;
			}
		}
		cout<<endl;
	}
	return 0;
}
