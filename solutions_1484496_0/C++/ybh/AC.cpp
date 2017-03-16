#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#define PB push_back

#define MAXN 25

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;

int b[2000000];

int dfs(int a[],int n,int i,int s)
{
	if (i>n) return 0;
	int x=s+a[i];
	if (b[x]==0) b[x]=1; else return x;	
	int y=dfs(a,n,i+1,x);
	if (y>0) return y;
	return dfs(a,n,i+1,s);
}

void dfs2(int a[],int ans[],int anssum,int n,int i,int s,int m,int &ans0)
{
	if (anssum==s && ans0<2)
	{
		for (int j=1;j<=m-1;j++)
			cout<<ans[j]<<' ';
		cout<<'\n';
		ans0++;
		return;
	}
	if (ans0==2) return;		
	if (i>n) return;
	if (s+a[i]<=anssum)
	{
		ans[m]=a[i];
		dfs2(a,ans,anssum,n,i+1,s+a[i],m+1,ans0);
	}
	if (ans0==2) return;
	dfs2(a,ans,anssum,n,i+1,s,m,ans0);
	return;
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	int TT;
	cin>>TT;
	for (int T=1;T<=TT;T++)
	{
		cout<<"Case #"<<T<<":"<<'\n';
		int n,a[MAXN],sum=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		for (int i=0;i<=sum;i++)
			b[i]=0;
		int x=dfs(a,n,1,0);
		//cout<<"x="<<x<<' ';
		if (x>0)
		{
			int ans[MAXN],ans0=0;
			dfs2(a,ans,x,n,1,0,1,ans0);
		}
		else cout<<"Impossible"<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
