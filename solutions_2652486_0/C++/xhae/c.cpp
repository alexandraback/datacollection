#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cnt[6];
int r, n, m, K;

int main(void)
{
	scanf("%*d");
	printf("Case #1:\n");
	scanf("%d %d %d %d", &r, &n, &m, &K);
	for(int i=0;i<r;i++)
	{
		memset(cnt, 0, sizeof(cnt));

		int data[7];
		for(int j=0;j<K;j++)
		{
			scanf("%d", data + j);
			int tcnt = 0;
			while(data[j] % 5 == 0) { data[j] /= 5; tcnt++; }
			cnt[5] = max(cnt[5], tcnt);

			tcnt = 0;
			while(data[j] % 3 == 0) { data[j] /= 3; tcnt++; }
			cnt[3] = max(cnt[3], tcnt);			
		}

		int left = 3 - cnt[3] - cnt[5];
		for(int j=0;j<K;j++)
		{
			int tcnt = 0;
			while(data[j] % 2 == 0) { data[j] /= 2; tcnt++; }
			cnt[4] = max(cnt[4], tcnt - left);
		}

		for(int i=0;i<3-cnt[3]-cnt[4]-cnt[5];i++) printf("2");
		for(int i=0;i<cnt[3];i++) printf("3");
		for(int i=0;i<cnt[4];i++) printf("4");
		for(int i=0;i<cnt[5];i++) printf("5");
		printf("\n");
	}

	return 0;
}

