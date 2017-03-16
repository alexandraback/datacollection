#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<string>
using namespace std;
string a[60];
int ma[60][60],d[60];
void solve()
{
	int n,m,i,b,c,f=1,j;
	string o="",co;
	stack<int>s;
	cin>>n>>m;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			ma[i][j]=0;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=0;i<m;i++)
	{
		cin>>b>>c;
		ma[b][c]=ma[c][b]=1;
	}
	for(i=0;i<n;i++)
		d[i]=i+1;
	do
	{
		while(!s.empty())
			s.pop();
		s.push(d[0]);
		for(i=1;i<n;i++)
		{
			while(ma[s.top()][d[i]]==0 && s.size()>1)
				s.pop();
			if(!ma[s.top()][d[i]])break;
			s.push(d[i]);
		}
		if(i!=n)continue;
		co="";
		for(i=0;i<n;i++)
			co+=a[d[i]];
		if(f || o>co)
		{
			o=co;
			f=0;
		}
	}
	while(next_permutation(d,d+n));
	cout<<o<<endl;
}
int main()
{
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
}
