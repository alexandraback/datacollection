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
long long total;
vector<int> no;
long long getans(long long a, long long n)
{
int i=n;
if(n>=total)
	return 0;
while(no[i] < a && i<total)
	{
	a+=no[i];
	i++;
	}
if(i==total)
	return 0;
long long t=1,po=2;
if(a!=1)
{
while( (po*(a-1) + 1) <= no[i])
	{
	t++;
	po*=2;
	}
long long newsize= (po*(a-1) + 1);
return min(total - i,t+getans(newsize,i));

}
else return (total-i);

}

int main()
{
long long t,test=0,n,i,a,ans;

sn(t);
while(t--)
{
test++;
sn(a);sn(n);
total =n;
no.clear();
no.resize(n);
REP(i,0,n)
	scanf("%d",&no[i]);
sort(no.begin(),no.end());

ans = getans(a,0);
printf("Case #%lld: %lld\n",test,ans);

}

}
