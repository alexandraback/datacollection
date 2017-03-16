#include<iostream>
using namespace std;
int x[10]={-1,-1,-1,0,0,0,1,1,1};
int y[10]={-1,0,1,-1,0,1,-1,0,1};
bool check(int i,int m)
{
	int br=0;
	while(i)
	{
		br++;
		i=i&(i-1);
	}
	return m!=br;
}
char s[50][50];
bool sysedi(int i,int j)
{
	int k,su=0;
	for(k=0;k<9;k++)
		su+=(s[i+x[k]][j+y[k]]=='*');
	return (su==0);
}
bool used[50][50];
int r,c,l;
int dfs(int i,int j)
{
	used[i][j]=1;
	if(!sysedi(i,j))return 1;
	int k,su=1;
	for(k=0;k<9;k++)
		if(used[i+x[k]][j+y[k]]==0)su+=dfs(i+x[k],j+y[k]);
	return su;
}
int pa()
{
	int i,j;
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			used[i][j]=0;
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
			if(sysedi(i,j))break;
		if(j<=c)break;
	}
	if(i>r)return 0;
	s[i][j]='c';
	return dfs(i,j);
}
void solve()
{
	int i,m,j,p,k;
	cin>>r>>c>>m;
	for(i=0;i<=r+5;i++)
		for(j=0;j<=c+5;j++)
		{
			used[i][j]=1;
			s[i][j]='.';
		}
	if(m==0 || r*c-m==1)
	{
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
				if(i==j && j==1)cout<<'c';
				else if(m==0)cout<<'.';
				else cout<<'*';
			cout<<endl;
		}
		return;
	}
	for(i=(1<<m)-1;i<(1<<(r*c));i++)
	{
		if(check(i,m))continue;
		for(j=0;j<r*c;j++)
		{
			if(((1<<j)&i)>0)s[j/c+1][j%c+1]='*';
			else s[j/c+1][j%c+1]='.';
		}
		l=i;
		p=pa();
		if(p==r*c-m)break;
	}
	if(i==(1<<(r*c)))
	{
		cout<<"Impossible\n";
		return;
	}
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
			cout<<s[i][j];
		cout<<"\n";
	}
}
int main()
{
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<":\n";
		solve();
	}
}
