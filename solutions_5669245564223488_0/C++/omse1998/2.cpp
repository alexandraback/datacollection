#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <vector>
#include <map>

#define p_b push_back
#define m_p make_pair



using namespace std;

int ttt,tt,x,n,a[2000],i,j,ans,c[2000],md,d[2000],qb,e[2000];
string s1,s[2000],s2[2000];
bool flag,t;

bool ift()
{
	int i;
	for (i=0; i<28; i++)
		c[i]=0;
	for (i=0; i<(int)s1.length(); i++)
	{
		if (c[s1[i]-'a']!=0)
			return false;
		j=i;
		while (j<(int)s1.length() && s1[j]==s1[i]) j++;
		c[s1[i]-'a']=1;
		i=j-1;
	}
	return true;
}

bool ift2()
{
	int i;
	for (i=0; i<28; i++)
		c[i]=-1;
	for (i=0; i<qb; i++)
	{
		for (j=0; j<s2[i].length(); j++)
		{
			if (c[s2[i][j]-'a']!=i && c[s2[i][j]-'a']!=-1)
				return false;
			c[s2[i][j]-'a']=i;
		}
	}
	return true;
}


int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>ttt;
	md=1000*1000*1000+7;
	for (tt=1; tt<=ttt; tt++)
	{
		cin>>n;
		for (i=0; i<n; i++)
			cin>>s[i];
		for (i=0; i<28; i++)
		{
			d[i]=0;
			e[i]=0;
		}
	   	for (i=0; i<n; i++)
	   	{
	   		flag=true;
	   		for (j=0; j<s[i].length(); j++)
	   			if (s[i][j]!=s[i][0])
	   			{
	   				flag=false;
	   				break;
	   			}
	   		if (flag)
	   		{
	   			d[s[i][0]-'a']++;
	   			e[i]=1;
	   		}

	   	}
	   	
		for (i=0; i<n; i++)
			a[i]=0;
		qb=0;
		flag=true;
		for (i=0; i<n; i++)
		{
			if (a[i]==0)
			{
				s1=s[i];
				a[i]=1;
				t=true;
				while (t)
				{
					t=false;
					for (j=0; j<n; j++)
					{
						if (a[j]==0 && e[j]==1 && s[j][(int)s[j].length()-1]==s1[0])
						{
							t=true;
							a[j]=1;
							s1=s[j]+s1;
							break;
						}
					}
					if (t) continue;
					for (j=0; j<n; j++)
					{
						if (a[j]==0 && s[j][(int)s[j].length()-1]==s1[0])
						{
							t=true;
							a[j]=1;
							s1=s[j]+s1;
							break;
						}
					}
				}
				if (!ift())
				{
					cout<<"Case #"<<tt<<": "<<0<<endl;	
					flag=false;
					break;
				}
				t=true;
				while (t)
				{
					t=false;
					for (j=0; j<n; j++)
					{
						if (a[j]==0 && e[j]==1 && s[j][0]==s1[(int)s1.length()-1])
						{
							t=true;
							a[j]=1;
							s1+=s[j];
							break;
						}
					}
						if (t) continue;
					for (j=0; j<n; j++)
					{
						if (a[j]==0 && s[j][0]==s1[(int)s1.length()-1])
						{
							t=true;
							a[j]=1;
							s1+=s[j];
							break;
						}
					}
				}
				if (!ift())
				{
					cout<<"Case #"<<tt<<": "<<0<<endl;	
					flag=false;
					break;
				}

				s2[qb]=s1;
				qb++;
			}
		}
		if (!ift2())
		{
			cout<<"Case #"<<tt<<": "<<0<<endl;	
			continue;
		}
		if (!flag) continue;
		ans=1;
		for (i=0; i<28; i++)
		{
			x=1;
			if (d[i]!=0)
			{
				for (j=1; j<=d[i]; j++)
					x=(x*j)	%md;
				d[i]=x;
			}
			
		}
		for (i=0; i<28; i++)
		{
			if (d[i]!=0)
				ans=(ans*d[i])%md;
		}
		for (i=0; i<qb; i++)
		{
			ans=(ans*(i+1))%md;
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	return 0;
}


