#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

char str[20];
int cnt[10100000],T,TT;
long long l,r;

bool par(char s[20])
{
	int len=strlen(s);
	for (int i=0;i<len/2;i++)
	{
		if (s[i]!=s[len-i-1]) return false;
	}
	return true;
}

bool test(long long x)
{
	sprintf(str,"%I64d",x);
	if (!par(str)) return false;
	sprintf(str,"%I64d",x*x);
	if (par(str)) return true;
	else return false;
}

int main()
{
	for (int i=1;i<=10000000;i++)
	{
		cnt[i]=cnt[i-1]+test(i);
	}
	scanf("%d",&T);
	while (T--)
	{
		cin>>l>>r;
		l=ceil(sqrt(l));r=floor(sqrt(r));
		printf("Case #%d: %d\n",++TT,cnt[r]-cnt[l-1]);
	}
	
	return 0;
}