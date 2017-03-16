#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const int MOD = 1000000007;
const int N = 1000005;
char s[N];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		int n,i;
		printf("Case #%d: ",ca++);
		scanf("%d%s",&n,s);
		int ret=0,tot=s[0]-'0';
		for(i=1;i<=n;i++)
		{
			if(tot<=i)
			{
				ret+=i-tot;
				tot=i;
			}
			tot+=s[i]-'0';
		}
		printf("%d\n",ret);
	}
	return 0;
}
