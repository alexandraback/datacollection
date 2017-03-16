
#include "stdio.h"
#define MAX_STRING 200

#include <string.h>

int Solve(char* str)
{
	int rv = 0;
	char cake_before = *str;
	if (*str == '\0')
		return 0;
	str++;
	while (*str != '\0')
	{
		if (cake_before != *str)
			rv++; // need to flip
		cake_before = *str;
		str++;
	}
	// at here, all pancakes is + or -
	if (cake_before == '-')
		rv++;
	return rv;
}

int main(int argc, char* argv[])
{
	char S[MAX_STRING + 1];
	int num;
	scanf("%d", &num);

	for (int i = 1; i < num + 1; i++)
	{
		int  answer;
		scanf("%s", &S);
		answer = Solve(S);
		printf("Case #%d: %d\n", i, answer);
	}

	return 0;
}

