#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define _ ios::sync_with_stdio(false);
#define mem(x,a) memset(x,(a),(int)(sizeof(x)))
#define pii pair<int,int>
#define fr(i,a,n) for(int i=(a);i<=(n);i++)
#define frd(i,a,n) for(int i=(a);i>=(n);i--)
#define nl cout<<endl
#define sp cout<<" "
#define pb push_back
#define mp make_pair 
#define F first 
#define S second
#define V vector
#define si size()
ll mod=1e9+7;
map<string,int> ma,mb;
void finda(string s)
{
	//cout<<s<<endl;
	int n=s.size(),flag=1;
	
	fr(i,0,n-1)
		if(s[i]=='?')flag=0;
	
	if(flag){
		if(ma[s])return;
		ma[s]=1;
		return ;
	}
	//cout<<s<<endl;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='?')
			for(char c='0';c<='9';c++)
				{
					s[i]=c;
					finda(s);
					s[i]='?';
				}
	}
}
void findb(string s)
{
	int n=s.size(),flag=1;
	
	fr(i,0,n-1)
		if(s[i]=='?')flag=0;
	
	if(flag){
		if(mb[s])return;
		mb[s]=1;
	}

	for(int i=0;i<n;i++)
	{
		if(s[i]=='?')
			for(char c='0';c<='9';c++)
				{
					s[i]=c;
					findb(s);
					s[i]='?';
				}
	}
}
int main() {_
	int t;cin>>t;
	fr(Z,1,t)
	{
		int ans=1e9,ia=1e9,ib=1e9;
		string sa,sb;
		ma.clear();
		mb.clear();
		string a,b;
		cin>>a>>b;
		//cout<<a<<endl;
		finda(a);
		findb(b);
		//for(auto i:ma)cout<<stoi(i.F)<<" ";
		
		for(auto i:ma)
		{
			for(auto j:mb)
			{
				string x=i.F;
				string y=j.F;
				int p=stoi(x);
				int q=stoi(y);
				int diff=abs(p-q);
				if(diff<ans)
				{
					sa=x;
					sb=y;
					ans=diff;
					ia=p;
					ib=q;
				}
				else if(diff==ans)
				{
					if(p<ia){
						sa=x;
						sb=y;
						ia=p;
						ib=q;
					}
					else if(p==ia && q<ib)
					{
						sa=x;
						sb=y;
						ia=p;
						ib=q;
					}
				}
			}
		}
		cout<<"Case #"<<Z<<": ";
		cout<<sa<<" "<<sb<<endl;
	}
	
	return 0;
}