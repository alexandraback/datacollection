#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<string>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<map>
#define fill(a,v) memset(a,v,sizeof(a))
#define sn(n) scanf("%lld",&n)
#define REP(i,a,b) for(i=a;i<b;i++)
#define MOD	1000000007
#define MAX 500001
using namespace std;

long long SmallC(long long n, long long r)
{
	vector< vector<long long> > C(2,vector<long long> (r+1,0));

	for (long long i=0; i<=n; i++)
	{
		for (long long k=0; k<=r && k<=i; k++)
			if (k==0 || k==i)
				C[i&1][k] = 1;
			else
				C[i&1][k] = (C[(i-1)&1][k-1] + C[(i-1)&1][k]);
	}
	return C[n&1][r];
}

int main()
{
long long t,test=0,n,i,a,x,y,row,prevtotal,tot;
double ans=0;

sn(t);
while(t--)
{
test++;
sn(n);sn(x);sn(y);
if(x<0)
{
row = (y-x)/2;
row++;
}
else if(x>0)
{
row = (x+y)/2;
row++;
}
else
{
row = (x+y+2)/2;
long long tot = 2*row*(row+1)-3*row;
if(tot <=n)
	ans=1;
else ans=0;	
printf("Case #%lld: %.8lf\n",test,ans);
continue;
}
long long tot = 2*row*(row+1)-3*row;
long long prevtotal =  2*row*(row-1)-3*(row-1);
if(tot<n  || (n-(prevtotal+2*row-2))>y )
	ans =1;
else if(prevtotal>=n  )
	ans =0;
else 
{
long long sum=0;
REP(i,0,y+1)
	{
	sum+=SmallC(n-prevtotal,i);}
ans = 1- sum/(double)pow(2.0,n-prevtotal);


}

printf("Case #%lld: %.8lf\n",test,ans);

}

}
