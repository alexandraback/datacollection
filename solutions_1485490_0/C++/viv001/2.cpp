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
int N,M;
int A[105],B[105];
long long int a[105],b[105];
long long int L[105][105];


long long int max(long long int a,long long int b)
{
	if(a>b)
		return a;
	else return b;
}

long long int subprob(int i,int j,long long int c1,long long int c2)
{
		if(i==N||j==M)
			L[i][j]=0;
		else
		{
			if(A[i]==B[j])
			{
				if(c1>c2)
					L[i][j] = max(c2 + subprob(i,j+1,c1-c2,b[j+1]),L[i][j]);
				else
					if(c2>c1)
					   L[i][j] = max(L[i][j],c1 + subprob(i+1,j,a[i+1],c2-c1));
					else
						L[i][j] = max(L[i][j],c1 + subprob(i+1,j+1,a[i+1],b[j+1]));
			}
			else
					L[i][j] = max(L[i][j],max(subprob(i+1,j,a[i+1],c2),subprob(i,j+1,c1,b[j+1]) ));
		}
	return L[i][j];
}


int main()
{
	int i,j,t,k;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		cin>>N>>M;
		for(i=0;i<N;i++)
		{
			scanf("%lld",&a[i]);
			scanf("%d",&A[i]);
		}
		for(i=0;i<M;i++)
		{
			scanf("%lld",&b[i]);
			scanf("%d",&B[i]);
		}

		for(i=0;i<=102;i++)
			for(j=0;j<=102;j++)
				L[i][j]=0;


		printf("Case #%d: %lld\n",k,subprob(0,0,a[0],b[0]));

	}

	return 0;
}
