#include <iostream>
#include <string.h>
using namespace std;
int mod=1000000007;
void add(unsigned long long int &ans,int k)
{
	for(int i=2;i<=k;i++)
	ans=(ans*i)%mod;
}
int main()
{
	int t,k;
	cin>>t;
	k=t;
	while(t--)
	{
		int n,i,j;
		cin>>n;
		string a[n];
		int m[26],s[26],e[26],p[26];
		bool flag=true,all=true;
		for(i=0;i<26;i++)
		{m[i]=p[i]=0;s[i]=e[i]=-1;}
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(flag)
			{
				for(j=1;j<a[i].length();j++)
				{
					if(a[i][j]==a[i][j-1])
					{
						a[i].erase(a[i].begin()+j);
						j--;
					}
				}
				for(j=1;j<a[i].length()-1&&flag;j++)
				{
					m[a[i][j]-'a']++;
					if(m[a[i][j]-'a']>1||s[a[i][j]-'a']!=-1||e[a[i][j]-'a']!=-1)flag=false;
				}
				if(a[i].length()>1)
				{
					all=false;
					if(s[a[i][0]-'a']==-1)s[a[i][0]-'a']=i;
					else flag=false;
					if(m[a[i][0]-'a']>0)flag=false;
					if(e[a[i][a[i].length()-1]-'a']==-1)e[a[i][a[i].length()-1]-'a']=i;
					else flag=false;
					if(m[a[i][a[i].length()-1]-'a']>0)flag=false;
					if(a[i][0]==a[i][a[i].length()-1])flag=false;
				}
				else
					p[a[i][0]-'a']++;
			}
		}
		cout<<"Case #"<<k-t<<": ";
		if(!flag)cout<<"0"<<endl;
		else
		{
			unsigned long long int ans=1;
			int count=0;
			if(all)
			{
				for(i=0;i<26;i++)
				if(p[i]>0)
				{
					count++;
					add(ans,p[i]);
				}
				add(ans,count);
				cout<<ans<<endl;
			}
			else
			{
				bool flag1=true;
				int used[n];
				for(i=0;i<n;i++)
				used[i]=-1;
				for(i=0;i<n;i++)
				{
					if(a[i].length()>1&&used[i]==-1)
					{
						used[i]=i;
						int next=a[i][a[i].length()-1]-'a';
						while(s[next]!=-1)
						if(used[s[next]]!=i)
						{
							used[s[next]]=i;
							next=a[s[next]][a[s[next]].length()-1]-'a';
						}
						else
						{
							flag1=false;
							break;
						}
						if(!flag1)break;
					}
				}
				if(!flag1)cout<<"0"<<endl;
				else
				{					
					for(i=0;i<26;i++)
					{
						if(p[i]>0)
						{
							add(ans,p[i]);
							if(s[i]==-1&&e[i]==-1)count++;
						}
						if(s[i]!=-1&&e[i]==-1)
						{
							count++;
						}
					}
					add(ans,count);
					cout<<ans<<endl;
				}
			}
		}
	}
	return 0;
}

