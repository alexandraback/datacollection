#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	char str[102];
	int T,cas=0,t;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);
		printf("Case #%d: %d\n",++cas,( t=(int)(unique(str,str+strlen(str))-str) ) - ( (t&1) ^ (str[0]=='+'?0:1) ));
	}
	return 0;
}
/*
5
-
-+
+-
+++
--+-
*/

