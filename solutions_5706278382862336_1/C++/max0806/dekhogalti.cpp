#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stdlib.h>
#include<algorithm>
#define i_n(a) scanf("%d",&a)
#define l_n(a) scanf("%lld",&a)
#define LL long long int
#define pb(a) push_back(a)
#define i_p(a) printf("%d\n",a)
#define l_p(a) printf("%lld\n",a)
#include<limits.h>

using namespace std;
int maximum(int a,int b)
{
    if(a>b)
        return a;
    else
    return b;
}
bool cmp(const pair<int, int>& firs, const pair<int, int>& sec)
 {
  return firs.first < sec.first;
 }
 LL gcd(LL a,LL b)
 {
 	if(!b)
		return a;
	return gcd(b,a%b);
 }
int main()
{
int t;
i_n(t);
LL a,b;
char ch;
for(int i=1;i<=t;i++)
{
	scanf("%lld%c%lld",&a,&ch,&b);
	printf("Case #%d: ",i);
	LL tm;
	tm=gcd(a,b);
	a=a/tm;
	b=b/tm;
	LL ma=(b&(b-1));
	if(ma!=0)
	{
		printf("impossible\n");
		continue;
	}
	LL cn=0;
	LL yum=2,yo=40;

	int flag=0;
	while(1)
	{
		if(cn>yo)
		{
			flag=1;
			break;
		}
		else if(a>=b)
			break;
		a=a*yum;
		cn++;
	}
	if(flag==0)
		l_p(cn);
	else
		printf("impossible\n");
}

 return 0;
}
