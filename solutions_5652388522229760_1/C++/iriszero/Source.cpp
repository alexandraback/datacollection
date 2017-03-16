#include <stdio.h>
#include <assert.h>
bool chk[10];
void make_chk(int N) 
{
	while(N>0)
	{
		int now = N % 10;
		chk[now] = true;
		N /= 10;
	}
}
bool is_chk()
{
	for (int i = 0; i < 10;i++)
	{
		if (!chk[i]) return false;
	}
	return true;
}
int solve()
{
	int N; scanf("%d", &N);
	if (N==0)
	{
		return -1;
	}
	
	for (int i = 0; i < 10; i++) chk[i] = false;
	for (int i = 1; i <= 500; i++)
	{
		make_chk(i*N);
		if (is_chk())
		{
			return i*N;
		}
	}
	assert(0);
}
int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		
		int ret = solve();
		printf("Case #%d: ", tc);
		if (ret==-1)
		{
			printf("INSOMNIA\n");
		}
		else
		{
			printf("%d\n", ret);
		}
	}
}