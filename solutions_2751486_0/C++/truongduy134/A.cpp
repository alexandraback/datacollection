#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_LEN 100

int getLenConsecutiveConsonant(char str[], int s, int e);
int getNValue(char str[], int n);

int main(void)
{
	int T, n, caseId;
	char str[MAX_LEN + 1];

	scanf("%d", &T);
	caseId = 1;
	while(caseId <= T)
	{
		scanf("%s %d", str, &n);

		printf("Case #%d: %d\n", caseId, getNValue(str, n));

		caseId++;
	}
	return 0;
}

int getNValue(char str[], int n)
{
	int len = (int) strlen(str), count = 0;

	for(int i = 0; i < len; i++)
		for(int j = i; j < len; j++)
			if(getLenConsecutiveConsonant(str, i, j) >= n)
				count++;

	return count;
}

int getLenConsecutiveConsonant(char str[], int s, int e)
{
	int i, maxLen = 0, len = 0;

	for(i = s; i <= e; i++)
		if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i'
			&& str[i] != 'o' && str[i] != 'u')
			len++;
		else
		{
			if(len > maxLen)
				maxLen = len;
			len = 0;
		}

	if(len > maxLen)
		maxLen = len;

	return maxLen;
}
