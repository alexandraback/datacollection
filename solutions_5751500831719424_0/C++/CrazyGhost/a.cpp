#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int cnt[200][200];   // [rangeid][stringid]
char ch[200][200];        // the char of this range [stringid][rangeid]
void solve(int T)
{
	memset(cnt, 0, sizeof(cnt));
	memset(ch, 0, sizeof(ch));
	int N;
	scanf("%d", &N);
	char buffer[205];
	gets(buffer);
	bool flag = false;
	for(int i = 0 ; i < N; i ++)
	{
		gets(buffer);
		int R = 0;
		char prev = 0; 
		for(char *p = buffer; *p >= 'a' && *p <= 'z'; p ++)
		{
			if(prev != *p)
				prev = ch[i][R ++] = *p;
			cnt[R - 1][i] ++;
		}
		if(i > 0 && strcmp(ch[i], ch[i-1]) != 0) flag = true;
	}
	if(flag)
	{
		printf("Case #%d: Fegla Won\n", T);
		return;
	}
	int ans = 0;
	int R = strlen(ch[0]);
	for(int i = 0; i < R; i ++)
	{
		sort(cnt[i], cnt[i] + N);
		int p = cnt[i][N/2];
		for(int j = 0; j < N; j ++)
			ans += abs(p - cnt[i][j]);
	}
	printf("Case #%d: %d\n", T, ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i ++)
		solve(i);
	return 0;
}
