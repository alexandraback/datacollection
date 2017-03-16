#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<iomanip>
using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b))
#define maxn 1000
int a[maxn],anum[maxn];
int b[maxn],bnum[maxn];
int n,m,Max;
void dfs(int x,int y,int sum)
{
	for(int i=x;i<n;i++)
		for(int j=y;j<m;j++)
			if(a[i]==b[j])
			{
				if(anum[i]>bnum[j])
				{
					sum+=bnum[j];
					anum[i]-=bnum[j];
					if(sum>Max) Max=sum;
					if(j+1<m)dfs(i,j+1,sum);
					sum-=bnum[j];
					anum[i]+=bnum[j];
				}
				else if(anum[i]<bnum[j])
				{
					sum+=anum[i];
					bnum[j]-=anum[i];
					if(sum>Max) Max=sum;
					if(i+1<n)dfs(i+1,j,sum);
					sum-=anum[i];
					bnum[j]+=anum[i];
				}
				else
				{
					sum+=anum[i];
					if(sum>Max) Max=sum;
					if(i+1<n&&j+1<m)dfs(i+1,j+1,sum);
					sum-=anum[i];
				}
			}
}
int main()
{
	ifstream cin("C-small-attempt0(1).in");
	ofstream cout("C-small-attempt0(1).out");
	int N;
	cin>>N;
	for(int k=1;k<=N;k++)
	{
		cin>>n>>m;
		int i;
		for(i=0;i<n;i++)
			cin>>anum[i]>>a[i];
		for(i=0;i<m;i++)
			cin>>bnum[i]>>b[i];
		Max=0;
		dfs(0,0,0);
		cout<<"Case #"<<k<<": "<<Max<<endl;
	}
	return 0;
}
