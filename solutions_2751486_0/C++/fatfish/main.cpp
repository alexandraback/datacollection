#include <stdio.h>
#include <string.h>

const int maxN = 100006;
char data[maxN];
int pre[maxN];
int n;

void inputData()
{
	scanf("%s%d", &data, &n);
}

bool isVowel(char val)
{
	switch (val)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		break;
	}

	return false;
}

void process(int cases)
{
	int len = strlen(data);

	for (int i = 0; i < len; ++ i)
	{
		if (isVowel(data[i]))
		{
			pre[i] = 0;
			continue;
		}

		if (i == 0)
		{
			pre[i] = 1;
		}
		else
		{
			pre[i] = pre[i - 1] + 1;
		}
	}

	long long ret = 0;
	for (int i = 0; i < len; ++ i)
	{
		int to = -1;
		for (int j = i + n - 1; j < len; ++ j)
		{
			if (pre[j] >= n)
			{
				to = j;
				break;
			}
		}

		if (to == -1)
		{
			break;
		}

		ret += (len - to);
	}
	printf("Case #%d: %lld\n", cases, ret);
}

int main()
{
	freopen("E:\\codejam\\A\\A-small-attempt0.in", "r", stdin);
	freopen("E:\\codejam\\A\\A.out", "w", stdout);

	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; ++ i)
	{
		inputData();
		process(i);
	}
	return 0;
}