#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cnt[9];
int r, n, m, K;

int main(void)
{
	scanf("%*d");
	printf("Case #1:\n");
	scanf("%d %d %d %d", &r, &n, &m, &K);
	for(int i=0;i<r;i++)
	{
		memset(cnt, 0, sizeof(cnt));

		long long data[12];
		int used[12];
		memset(used, 0, sizeof(used));

		for(int j=0;j<K;j++)
		{
			scanf("%lld", data + j);
			int tcnt = 0;
			while(data[j] % 5 == 0) { data[j] /= 5; tcnt++; }
			cnt[5] = max(cnt[5], tcnt);
			used[j] += tcnt;

			tcnt = 0;
			while(data[j] % 7 == 0) { data[j] /= 7; tcnt++; }
			cnt[7] = max(cnt[7], tcnt);			
			used[j] += tcnt;
		}

		bool twoExist = false, threeExist = false;
		for(int j=0;j<K;j++)
		{
			int cnt2 = 0;
			while(data[j] % 2 == 0) { data[j] /= 2; cnt2++; }
			
			int cnt3 = 0;
			while(data[j] % 3 == 0) { data[j] /= 3; cnt3++; }

			if(cnt2) twoExist = true;
			if(cnt3) threeExist = true;

			int left = 6 - used[j];
			if(cnt2 > left * 2) { cnt[8] = max(cnt[8], min(cnt2 - left * 2, cnt2 / 3)); left -= min(cnt2 - left * 2, cnt2 / 3); cnt2 -= min(cnt2 - left * 2, cnt2 / 3) * 3; }
			if(cnt2 > left) { cnt[4] = max(cnt[4], min(cnt2 - left, cnt2 / 2)); left -= min(cnt2 - left, cnt2); cnt2 -= min(cnt2 - left, cnt2 / 2) * 2; }

			if(left >= cnt2 + cnt3)
			{
				cnt[2] = max(cnt[2], cnt2);
				cnt[3] = max(cnt[3], cnt3);
			}
			else
			{
				int cnt6 = cnt2 + cnt3 - left;
				cnt[6] = max(cnt[6], cnt6);
				cnt[2] = max(cnt[2], cnt2 - cnt6);
				cnt[3] = max(cnt[3], cnt3 - cnt6);
			}
		}

		int totCnt = 12;
		for(int i=0;i<cnt[5];i++) { printf("5"); totCnt--; }
		for(int i=0;i<cnt[7];i++) { printf("7"); totCnt--; }

		bool isTwo = false, isThree = false;
		for(int i=0;i<cnt[8] && totCnt;i++)
		{
			totCnt--;
			if(totCnt == 0 && threeExist && isThree == false)
			{				
				printf("3");
				break;
			}
			printf("8");
			isTwo = true;
		}
		for(int i=0;i<cnt[4] && totCnt;i++)
		{
			totCnt--;
			if(totCnt == 0 && threeExist && isThree == false)
			{
				printf("3");
				break;
			}
			printf("4");
			isTwo = true;				
		}
		for(int i=0;i<cnt[6] && totCnt;i++)
		{
			isTwo = true;
			isThree = true;
			totCnt--;
			printf("6");
		}		
		for(int i=0;i<cnt[3] && totCnt;i++)
		{
			totCnt--;
			if(totCnt == 0 && twoExist && isTwo == false)
			{
				printf("2");
				break;
			}
			printf("3");
			isThree = true;				
		}
		for(int i=0;i<cnt[2] && totCnt;i++)
		{
			totCnt--;
			printf("2");
			isTwo = true;				
		}
		for(int i=0;i<totCnt;i++) printf("%d", rand() % 2 + 2);
			
		printf("\n");
	}

	return 0;
}


