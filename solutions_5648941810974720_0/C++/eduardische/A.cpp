#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
#include <string>
#define MAXN 2005

using namespace std;

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static char s[MAXN];
	static int cnt[256];
	static int res[10];
	for (iT = 0; iT < T; iT++)
	{
		scanf("\n%s",s);
		int N = strlen(s);
		memset(cnt,0,sizeof(cnt));
		int i;
		for (i = 0; i < N; i++)
		{
			cnt[(int)(s[i])]++;
		}
		memset(res,0,sizeof(res));
		res[0] = cnt['Z'];
		res[2] = cnt['W'];
		res[4] = cnt['U'];
		res[5] = cnt['F'] - res[4];
		res[6] = cnt['X'];
		res[7] = cnt['V'] - res[5];
		res[8] = cnt['G'];
		res[1] = cnt['O'] - res[0] - res[2] - res[4];
		res[9] = cnt['I'] - res[5] - res[6] - res[8];
		res[3] = cnt['R'] - res[0] - res[4];
		printf("Case #%d: ",iT+1);
		for (i = 0; i < 10; i++)
		{
			for (int j = 0; j < res[i]; j++) printf("%d",i);
		}
		printf("\n");
	}
	return 0;
}
