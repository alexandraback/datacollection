#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int a[100],b[100],c[100];
string st[1000];
long long p=1000000007;
int fa[1000];
long long ans;
int haha;

long long ha(int x)
{
	long long ans=1;
	for (int i=1;i<=x;i++)
		ans=(ans*i) % p;
	return ans;
}

int f(int x)
{
	if (fa[x]==x) return x;
	fa[x]=f(fa[x]);
	return fa[x];
}

int update(int x)
{
	string s=st[x];
	char ch=s[0];
	bool tf=true;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]!=ch)
		{
			tf=false;
			break;
		}
	}
	if (tf)
	{
		c[ch-'a']++;
		haha--;
		return 1; 
	}
	int m=s.length();
	if (s[0]==s[m-1]) return 0;
	for (int i=0;i<m;i++)
	{
		if (ch!=s[i])
		{
			if (b[ch-'a']>0) return 0;
			b[ch-'a']=x+1;
			ch=s[i];
			if (a[ch-'a']>0) return 0;
			a[ch-'a']=x+1;
		}
	}
	return 1;
}


int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin>>t;
	for (int ii=0;ii<t;ii++)
	{
		int n;
		cin>>n;
		haha=n;
		ans=1;
		cout<<"Case #"<<ii+1<<": ";
		for (int i=0;i<n;i++)
			cin>>st[i];
		for (int i=0;i<100;i++)
		{
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}
		for (int i=0;i<n;i++)
		{
			ans=ans*update(i);
		}
		if (ans==0)
		{
			cout<<0<<endl;
			continue;
		}
		for (int i=0;i<=n;i++)
		{
			fa[i]=i;
		}
		int k=0;
		int l=0;
		for (int i=0;i<26;i++)
		{
			if (a[i]==0 && b[i]==0 && c[i]>0)
			{
				k++;
				continue;
			}
			if (a[i]>0 && b[i]==0)
				k++;
			if (a[i]>0 && b[i]>0 && a[i]!=b[i])
			{
				int aa=f(a[i]);
				int bb=f(b[i]);
				if (aa==bb)
				{
					ans=0;
					break;
				}
				fa[aa]=bb;
			}
		}
		if (ans==0)
		{
			cout<<ans<<endl;
			continue;
		}
		ans=ha(k);
//		cout<<ans<<endl;
		for (int i=0;i<26;i++)
		{
			ans=(ans*ha(c[i]))%p;
		}
		cout<<ans<<endl;
	}
}