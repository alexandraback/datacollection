#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cctype>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
double pt[205];
double res[205];
bool judge(double m,int n,double sum)
{
	double dsum=0;
	for(int i=0;i<n;i++)
	{
		if(pt[i]<m)
		{
			dsum+=m-pt[i];
		}
	}
	return dsum<=sum;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T;
	int N;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&N);
		double sum=0;
		for(int i=0;i<N;i++){scanf("%lf",pt+i);sum+=pt[i];}
		double aver=sum*2/N;
		double l=0,r=1e5,m;
		for(int i=0;i<300;i++)
		{
			m=(l+r)/2;
			if(judge(m,N,sum))l=m;
			else r=m;
		}
		for(int i=0;i<N;i++)
		{
			if(pt[i]>=m)res[i]=0;
			else res[i]=100*(m-pt[i])/sum;
		}
		
		printf("Case #%d:",t);
		for(int i=0;i<N;i++)printf(" %lf",res[i]);
		puts("");
		
	}
	
	return 0;
}