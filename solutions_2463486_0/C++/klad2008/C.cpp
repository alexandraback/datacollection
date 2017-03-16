#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
int s[200],f[20000000];
int test,A,B;
bool pd(long long x)
{
	int len=0;
	while (x)s[++len]=x%10,x=x/10;
	for (int i=1;i<=len;i++)
	if (s[i]!=s[len-i+1])return false;
	return true;
}
bool ok(int i){if (pd(i)&&pd((long long)(i)*i))return true;return false;}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&test);
	for (int i=1;i<=10000000;i++)
	if (ok(i))f[i]=f[i-1]+1;
	else f[i]=f[i-1];
	for (int tt=1;tt<=test;tt++)
	{
		scanf("%d%d",&A,&B);
		printf("Case #%d: %d\n",tt,f[int(sqrt(B))]-f[int(sqrt(A-1))]);
	}
}
