#include <stdio.h>
#include <fstream>
#include <iomanip> 
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdlib.h> 
#include <set>
#include <queue>
#include <string>
#include <string.h>
using namespace std;
//#pragma comment(linker, "/STACK:999999999")
#define ll long long
const long long MAXN = 102;
const long long INF=999999999;
const long double eps=0.00000000001;
const long long mod=1000000007;

string sim(string s)
{
	string a="";
	a+=s[0];
	for (int i=1;i<s.length();i++)
	{
		if (s[i]!=s[i-1])
			a+=s[i];
	}
	return a;
}


long long fac(int x)
{
	long long res=1;
	for (int i=1;i<=x;i++)
	{
		res*=i;
		res=res%mod;
	}
	return res;
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int q;
	cin>>q;
	for (int ss=1;ss<=q;ss++)
	{
		cout<<"Case #"<<ss<<": ";
		int n;
		cin>>n;
		string b;
		vector <string> v;
		for (int i=0;i<n;i++)
		{
			cin>>b;
			b=sim(b);
			v.push_back(b);
		}
		vector <int> mid(255,0);
		for (int j=0;j<n;j++)
		{
			for (int i=1;i<v[j].length()-1;i++)
				mid[v[j][i]]++;
		}
		int f=0;
		for (int j=0;j<n;j++)
		{
			for (int i=1;i<v[j].length()-1;i++)
				if (mid[v[j][i]]>1)
					f=1;
		}
		vector <int> st(255,0),fh(255,0),one(255,0);

		for (int j=0;j<n;j++)
		{
			if (v[j].length()!=1)
			{
					if (v[j][0]==v[j][v[j].length()-1])
						f=1;
					st[v[j][0]]++;
					fh[v[j][v[j].length()-1]]++;
			}
			else
			{
				one[v[j][0]]++;
			}
			if (mid[v[j][0]]!=0)
				f=1;
			if (mid[v[j][v[j].length()-1]]!=0)
				f=1;
		}
		for (int i=0;i<255;i++)
		{
			if (st[i]>1)
				f=1;
			if (fh[i]>1)
				f=1;
		}
		if (f==1)
		{
			cout<<0<<endl;
		}
		else
		{
			vector <int> ff;
			vector <bool> used(n,false),us(255,false);
			int k=0;
			int u=99999;
			int DD=n;
			for (int i=0;i<255;i++)
				DD-=one[i];
			long long w=1;
			while (k<DD)
			{
					k++;
					if (u==99999)
					{
					for (int i=0;i<n;i++)
						if ((!used[i])&&(v[i].length()!=1))
							if (fh[v[i][0]]==0)
								u=min(u,i);
					}
					if (u==99999)
					{
						cout<<0<<endl;
						f=1;
						k=99999;
					}
					else
					{
					if (!us[v[u][0]])
					{
						if (one[v[u][0]]>1)
						{
								w*=fac(one[v[u][0]]);
								w=w%mod;
						}
					}
					us[v[u][0]]=true;
					char z=v[u][v[u].length()-1];
					used[u]=true;
					us[z]=true;
				
					if (one[z]>1)
					{
							w*=fac(one[z]);
							w=w%mod;
					}
					if (st[z]>0)
					{
						for (int i=0;i<n;i++)
						{
							if ((!used[i])&&(v[i].length()!=1))
								if (v[i][0]==z)
								{
									u=i;
								}
						}
					}
					else
					{
						ff.push_back(w);
						u=99999;
						w=1;
					}
					}
			}
			for (int i=0;i<255;i++)
				if ((!us[i])&&(one[i]>0))
					ff.push_back(fac(one[i]));
			w=fac(ff.size());
			w=w%mod;
			for (int i=0;i<ff.size();i++)
			{
				w*=ff[i];
				w=w%mod;
			}
			if (f!=1)
				cout<<w<<endl;
			
		}





	}


	return 0;
}