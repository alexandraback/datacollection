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
char s[500][500];
bool sysedi(int i,int j)
{
	int k,su=0;
	for(k=0;k<9;k++)
		su+=(s[i+x[k]][j+y[k]]=='*');
	return (su==0);
}
bool used[500][500];
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
	for(i=r;i>0;i--)
	{
		for(j=c;j>0;j--)
			if(sysedi(i,j))break;
		if(j>0)break;
	}
	if(i==0)return 0;
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
	s[r][c]='c';
	i=j=1;
	p=m;
	while(m)
	{
		if(r-i>=c-j)
		{
			for(k=j;k<=c;k++)
			{
				if(m==1 && k+1==c)break;
				if(m)
				{
					m--;
					s[i][k]='*';
				}
			}
			i++;
		}
		else
		{
			for(k=i;k<=r;k++)
			{
				if(m==1 && k+1==r)break;
				if(m)
				{
					m--;
					s[k][j]='*';
				}
			}
			j++;
		}
	}
	if(pa()!=r*c-p)
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
