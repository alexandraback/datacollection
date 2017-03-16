#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 5010

char st[MAX_N];
char ans[MAX_N * 2];
int l, r;
int n;

void work()
{
	n = strlen(st);
	l = n;
	r = n + 1;
	ans[l] = st[0];
	for (int i = 1; i < n; i++)
	{
		if (st[i] >= ans[l])
			ans[--l] = st[i];
		else
			ans[r++] = st[i];
	}
	ans[r] = 0;
}

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d: ", case_num);
		scanf("%s", st);
		work();
		puts(ans + l);
	}
	return 0;
}
