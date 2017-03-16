#include <stdio.h>
#include <string.h>

const int maxN = 1000006;
char data[maxN];
int pre[maxN];
int pLen;
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

	pLen = 0;
	int cur = 0;
	for (int i = 0; i < len; ++ i)
	{
		if (isVowel(data[i]))
		{
			cur = 0;
			continue;
		}

		++ cur;
		if (cur >= n)
		{
			pre[pLen] = i;
			++ pLen;
		}
	}

	long long ret = 0;
	int lastFrom = -1;
	for (int i = 0; i < pLen; ++ i)
	{
		int fromIndex = pre[i] - n + 1;
		int toIndex = pre[i];

		ret += (fromIndex - lastFrom) * (len - toIndex);
		lastFrom = fromIndex;
	}
	printf("Case #%d: %lld\n", cases, ret);
}

int main()
{
	freopen("E:\\codejam\\A\\A-large.in", "r", stdin);
	freopen("E:\\codejam\\A\\AA.out", "w", stdout);

	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; ++ i)
	{
		inputData();
		process(i);
	}
	return 0;
}