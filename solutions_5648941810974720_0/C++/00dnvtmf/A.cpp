//writed by dnvtmf
#include <bits/stdc++.h>
#define INF 1000000007
#define FI first
#define SE second
#define PB push_back
#define VI vector<int>
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
const int NUM = 100010;
char number[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char s[2010];
int len, cnt[128];
int ans[10];
void check()
{
	for(char c = 'A'; c <= 'Z'; ++c)
	{
        int num = cnt[c];
        for(int i = 0; i < 10; ++i)
		{
			for(int j = 0; number[i][j]; ++j)
				if(number[i][j] == c)
					num -= ans[i];
		}
		if(num != 0)
		{
			puts("Error");
			exit(-1);
		}
	}
}
int main()
{
#ifdef ACM_TEST
    freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
#endif
    /*
    for(char c = 'A'; c <= 'Z'; ++c)
    {
        putchar(c);
        for(int i = 0; i <= 9; ++i)
        {
            for(int j = 0; number[i][j]; ++j)
                if(number[i][j] == c)
                {
                    printf(" %d", i);
                    break;
                }
        }
        puts("");
    }*/
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        scanf("%s", &s);
        len = strlen(s);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < len; ++i)
        {
            ++cnt[s[i]];
        }
        memset(ans, 0, sizeof(ans));
        ans[0] = cnt['Z'];
        ans[2] = cnt['W'];
        ans[4] = cnt['U'];
        ans[6] = cnt['X'];
        ans[8] = cnt['G'];
        ans[3] = cnt['H'] - ans[8];
        ans[5] = cnt['F'] - ans[4];
        ans[7] = cnt['S'] - ans[6];
        ans[9] = cnt['I'] - ans[5] - ans[6] - ans[8];
        ans[1] = cnt['N'] - ans[7] - 2 * ans[9];
        printf("Case #%d: ", cas);
        for(int i = 0; i < 10; ++i)
		{
			for(int j = 0; j < ans[i]; ++j)
			{
				putchar('0' + i);
			}
		}
		puts("");
		check();
    }
    return 0;
}
