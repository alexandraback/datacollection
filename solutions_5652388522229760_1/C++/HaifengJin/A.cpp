#include <cstdio>
#include <cstring>
using namespace std;

int n;
bool vis[100];

void record_digits(int a)
{
	while (a > 0)
	{
		vis[a % 10] = true;
		a /= 10;
	}
}

bool ok()
{
	for (int i = 0; i < 10; i++)
	{
		if (!vis[i])
		{
			return false;
		}
	}
	return true;
}

int work(int n)
{
	if (n == 0)
		return -1;
	memset(vis, 0, sizeof(vis));
	int temp = n;
	record_digits(temp);
	while (!ok())
	{
		temp += n;
		record_digits(temp);
	}
	return temp;
}

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		scanf("%d", &n);
		case_num++;
		printf("Case #%d: ", case_num);
		int ans = work(n);
		if (ans == -1)
			puts("INSOMNIA");
		else
			printf("%d\n", ans);

	}
	return 0;
}
