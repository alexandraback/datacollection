#include<bits/stdc++.h>

using namespace std;
#define in(n) scanf("%lld",&n)
#define ll long long
#define MOD 1000000007

vector<int> possible;
ll n,J;
int location[40];

void win()
{
	int i,j,k,l;
	string divisor;
	for(i=1;i<n/2;i++)
	{
		possible.push_back(n-i);
	}

	divisor = " 3 4 5 6 7 8 9 10 11";
	//c1
	for(i=1;i<=n;i++)
		location[i]=0;
	location[1]=1;
	location[n]=1;
	for(i=0;i<possible.size();i++)
	{
		if(J==0)
			return;
		location[possible[i]]=1;
		location[n-possible[i]+1]=1;
		for(j=1;j<=n;j++)
		{
			cout<<location[j];
		}
		cout<<divisor<<endl;
		location[possible[i]]=0;
		location[n-possible[i]+1]=0;
		J--;
	}

	//c2
	for(i=0;i<possible.size();i++)
	{
		location[possible[i]]=1;
		location[n-possible[i]+1]=1;
		for(k=i+1;k<possible.size();k++)
		{
			if(J==0)
				return;
			location[possible[k]]=1;
			location[n-possible[k]+1]=1;
			for(j=1;j<=n;j++)
			{
				cout<<location[j];
			}
			cout<<divisor<<endl;
			location[possible[k]]=0;
			location[n-possible[k]+1]=0;
			J--;
		}
		location[possible[i]]=0;
		location[n-possible[i]+1]=0;
	}

	//c3
	for(l=0;l<possible.size();l++)
	{
		location[possible[l]]=1;
		location[n-possible[l]+1]=1;	
		for(i=l+1;i<possible.size();i++)
		{
			location[possible[i]]=1;
			location[n-possible[i]+1]=1;
			for(k=i+1;k<possible.size();k++)
			{
				if(J==0)
					return;
				location[possible[k]]=1;
				location[n-possible[k]+1]=1;
				for(j=1;j<=n;j++)
				{
					cout<<location[j];
				}
				cout<<divisor<<endl;
				location[possible[k]]=0;
				location[n-possible[k]+1]=0;
				J--;
			}
			location[possible[i]]=0;
			location[n-possible[i]+1]=0;
		}
		location[possible[l]]=0;
		location[n-possible[l]+1]=0;
	}
}

int main()
{
	long long t;
	in(t);
	ll ans;
	for(int i=1;i<=t;i++)
	{
		in(n);
		in(J);
		cout<<"Case #"<<i<<":"<<endl;
		win();
	}
}