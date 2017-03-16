#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include <iomanip>   
using namespace std;
int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("B-small-attempt0.in");
	cout.open("B-small-attempt0.txt");
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		int k,l,s,j;
		cin>>k>>l>>s;
		string key,target;
		cin>>key>>target;
		int a[30],b[30];
		for(j=0;j<26;j++)
		{
			a[j]=b[j]=0;
		}
		int x=target.length();
		for(j=0;j<k;j++)
		{
			a[key[j]-'A']++;
		}
		double ans=1.0;
		for(j=0;j<l;j++)
		{
			double x=((a[target[j]-'A']*1.0)/(k*1.0));
			ans=ans*1.0*x;
		}
		int temp=s/l;
		int temp2=s%l;
		if(ans==0.0)
		{
			ans=0.0;
		}
		else
		{
			if(temp2==0)
			{
				ans=1-ans;
				ans=ans*temp;
			}
			else
			{
				ans=1-ans;
				ans=ans*(temp+1);
			}
		}
		cout<<"Case #"<<i<<": ";
		cout<<setprecision(7)<<ans<<endl;
	}
}
