#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;


ifstream fin("B-small-attempt2.in");
ofstream fout("ans.txt");
#define cin fin
#define cout fout

long long ans;
long long res1, res2;
//bool flag;

void work(string a, string b, bool f)
{
	int n = a.length();
	long long tmp;
	long long p = 0, q = 0;
	for(int j = 0; j <= n; j++)
	{
		bool flag = true;
		for(int i = 0; i < j; i++)
		{
			if(a[i]!='?'&&b[i]!='?'&&a[i]!=b[i])
			{flag=false;break;}
		}
		if(!flag) continue;
		p=q=0;
		for(int i = 0; i < j; i++)
		{
			if(a[i]==b[i])
			{
				if(a[i]=='?')
				{
					p*=10;
					q*=10;
				}
				else
				{
					p=p*10+(a[i]-'0');
					q=q*10+(a[i]-'0');
				}
			}
			else
			{
				if(a[i]=='?')
				{
					p=p*10+(b[i]-'0');
					q=q*10+(b[i]-'0');
				}
				else
				{
					p=p*10+(a[i]-'0');
					q=q*10+(a[i]-'0');
				}
			}
		}
		
		long long px = p, qx = q;
		if(j==n)
		{
			
		tmp=max(p-q, q-p);
		if(tmp < ans || tmp==ans && p < res1 || tmp==ans && p==res1&& q < res2)
		{
			{
				ans=tmp;
				res1=p;
				res2=q;
			}
		}
		continue;}
		
		
		for(int k=0;k<=8;k++)
		{
			
		
		
		p=px;q=qx;
		if(a[j]!='?')
			p=p*10+(a[j]-'0');
			else
			p=p*10+k;
			if(b[j]!='?')
			q=q*10+(b[j]-'0');
			else
			q=q*10+k+1;
		for(int i = j+1; i < n; i++)
		{
			if(a[i]!='?')
				p=p*10+(a[i]-'0');
			else
				p=p*10;
			if(b[i]!='?')
				q=q*10+(b[i]-'0');
			else
				q=q*10 + 9;
		}
		
		tmp=max(p-q, q-p);
		if(tmp < ans || tmp==ans && p < res1 || tmp==ans && p==res1&& q < res2)
		{
			{
				ans=tmp;
				res1=p;
				res2=q;
			}
		}
		p=px;
		q=qx;
		if(a[j]!='?')
			p=p*10+(a[j]-'0');
			else
			p=p*10+k;
			if(b[j]!='?')
			q=q*10+(b[j]-'0');
			else
			q=q*10+k+1;
		for(int i = j+1; i < n; i++)
		{
			if(a[i]!='?')
				p=p*10+(a[i]-'0');
			else
				p=p*10+9;
			if(b[i]!='?')
				q=q*10+(b[i]-'0');
			else
				q=q*10;
		}
		tmp=max(p-q, q-p);
		if(tmp < ans || tmp==ans && p < res1 || tmp==ans && p==res1&& q < res2)
		{
				ans=tmp;
				res1=p;
				res2=q;
		}
		
		
		p=px;q=qx;
		if(a[j]!='?')
			p=p*10+(a[j]-'0');
			else
			p=p*10+k+1;
			if(b[j]!='?')
			q=q*10+(b[j]-'0');
			else
			q=q*10+k;
		for(int i = j+1; i < n; i++)
		{
			if(a[i]!='?')
				p=p*10+(a[i]-'0');
			else
				p=p*10;
			if(b[i]!='?')
				q=q*10+(b[i]-'0');
			else
				q=q*10 + 9;
		}
		
		tmp=max(p-q, q-p);
		if(tmp < ans || tmp==ans && p < res1 || tmp==ans && p==res1&& q < res2)
		{
			{
				ans=tmp;
				res1=p;
				res2=q;
			}
		}
		p=px;
		q=qx;
		if(a[j]!='?')
			p=p*10+(a[j]-'0');
			else
			p=p*10+k+1;
			if(b[j]!='?')
			q=q*10+(b[j]-'0');
			else
			q=q*10+k;
		for(int i = j+1; i < n; i++)
		{
			if(a[i]!='?')
				p=p*10+(a[i]-'0');
			else
				p=p*10+9;
			if(b[i]!='?')
				q=q*10+(b[i]-'0');
			else
				q=q*10;
		}
		tmp=max(p-q, q-p);
		if(tmp < ans || tmp==ans && p < res1 || tmp==ans && p==res1&& q < res2)
		{
				ans=tmp;
				res1=p;
				res2=q;
		}}
	}
}

int main()
{
	int T;
	cin>>T;
	for(int t = 1; t <= T; t++)
	{
		string s1, s2;
		cin>>s1>>s2;
		cout<<"Case #"<<t<<": ";
		
		ans=1000000000000000000ll;
		
		work(s1, s2, 0);
		//work(res2, res1, 1);
		
		cout<<setfill('0')<<setw(s1.length())<<res1<<" "<<setfill('0')<<setw(s1.length())<<res2<<endl;
	}
	
	
	return 0;
}

