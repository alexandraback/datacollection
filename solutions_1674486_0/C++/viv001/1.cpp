// Author : Vivek Hamirwasia

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<utility>
#include<cstring>
#include<map>
#define ll long long int
#define MAX 1000000007
using namespace std;
int A[1001][1001];
int C[1001][1001];
int N,flag,m[1002];


void solve(int parent,int ver)
{
	int i,tex;

	for(i=1;i<=m[ver];i++)
	{
		tex = A[ver][i];
		C[parent][tex]++;
		if(C[parent][tex]==2)
		{
			flag=1;
			return;
		}
		solve(parent,tex);
		if(flag==1)
			return;
	}
}

int main()
{
	int i,j,T,v,k;
	cin>>T;
	for(k=1;k<=T;k++)
	{
		flag=0;
		scanf("%d",&N);
		for(i=1;i<=N;i++)
		{
			scanf("%d",&m[i]);
			for(j=1;j<=m[i];j++)
			{
				scanf("%d",&v);
				A[i][j]=v;
			}
		}

		for(i=1;i<=N;i++)
		{
			solve(i,i);
		}

		if(flag==1)
			printf("Case #%d: Yes\n",k);
		else
			printf("Case #%d: No\n",k);

		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				C[i][j]=0;


	}
	return 0;
}
