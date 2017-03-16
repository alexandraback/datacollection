#include <stdio.h>
#include <string.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int totalCases, caseNo;		scanf("%d", &totalCases);
	for (caseNo = 1; caseNo <= totalCases; ++caseNo)
	{
		char s[101], presentSide = '+';
		scanf("%s", s);
		int i, count = 0;
		for (i = strlen(s)-1; i >= 0; --i)
		{
			if (s[i] != presentSide)
			{
				count++;
				presentSide = s[i];
			}
		}
		printf("Case #%d: %d\n", caseNo, count);
	}
	return 0;
}
