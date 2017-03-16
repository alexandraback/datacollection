#include "stdafx.h"
#include <cstring>

char str[2000000];

bool isCon(char c)
{
	switch (c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return false;
	default:
		return true;
	}
}

int main()
{
	int t;

	FILE* in = fopen("A-small-attempt0 (1).in", "r");
	FILE* out = fopen("a.out.txt", "w");
	fscanf(in, "%d", &t);

	for (int it = 1; it <= t; it++)
	{
		int n;
		fscanf(in, "%s %d", str, &n);

		long long result = 0;

		int conCount = 0;
		for (int i = 0; i < n; i++)
		{
			if (isCon(str[i])) conCount++;
		}

		int len = strlen(str);
		int lastPos = -1;
		for (int i = 0; i < len; i++)
		{
			if (conCount == n)
			{
				long long temp = i - lastPos;
				temp = temp * (len - (i + n) + 1);
				result += temp;
				lastPos = i;
			}
			if (isCon(str[i])) conCount--;
			if (i + n == len) break;
			if (isCon(str[i + n])) conCount++;
		}

		fprintf(out, "Case #%d: %d\n", it, result);
	}
}