#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
long long s[200],f[20000000];
long long test,A,B;
bool pd(long long x)
{
	long long len=0;
	while (x)s[++len]=x%10,x=x/10;
	for (long long i=1;i<=len;i++)
	if (s[i]!=s[len-i+1])return false;
	return true;
}
bool ok(long long i){if (pd(i)&&pd((long long)(i)*i))return true;return false;}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%I64d",&test);
	for (long long i=1;i<=10000000;i++)
	if (ok(i))f[i]=f[i-1]+1;
	else f[i]=f[i-1];
	for (long long tt=1;tt<=test;tt++)
	{
		scanf("%I64d%I64d",&A,&B);
		printf("Case #%I64d: %I64d\n",tt,f[int(sqrt(B))]-f[int(sqrt(A-1))]);
	}
}
