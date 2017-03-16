#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int test,len,ans;
char str[111];
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B2.out","w",stdout);
	cin>>test;
	for (int nmb=1;nmb<=test;++nmb)
	{
		ans=0;
		scanf("%s",str+1);
		len=strlen(str+1);
		for (;str[len]=='+';--len);
		for (;len;--len) if (str[len]!=str[len+1]) ans++;
		printf("Case #%d: %d\n",nmb,ans);
	}
	return 0;
}
