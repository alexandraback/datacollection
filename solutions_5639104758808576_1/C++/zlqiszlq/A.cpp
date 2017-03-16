#include <cstdio>
#include <string>
using namespace std;
#define MAXS 1510

int T;
char S[MAXS];


int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for (int cases = 1 ;cases <= T; ++ cases)
	{
		int sn, cnt, ans;
		scanf("%d%s",&sn,S);
		cnt = 0;
		ans = 0;
		for (int i=0;i<=sn;++i)
		{
			if (cnt < i)
			{
				++ ans;
				++ cnt;
			}
			cnt += S[i] - '0';
		}
		printf("Case #%d: %d\n",cases, ans);
	}
	return 0;
}
