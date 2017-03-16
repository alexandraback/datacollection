#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 150;

char st[MAX_N];
int n;

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		scanf("%s", st);
		n = strlen(st);
		int m = unique(st, st + n) - st;
		if (st[m - 1] == '+')
			m--;
		case_num++;
		printf("Case #%d: ", case_num);
		printf("%d\n", m);
	}
	return 0;
}
