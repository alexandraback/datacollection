#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <set>
using namespace std;

char A[1000], B[1000], C[1000];
int length;

bool increase(char *num, int len)
{
	num[len-1]++;
	for (int i = len - 1; i >= 1; i--)
	{
		if (num[i] > '9')
		{
			num[i] -= 10;
			num[i-1]++;
		}
		else break;
	}
	return num[0] <= '9';
}

void rotate(char *num, int len)
{
	char tmp = num[0];
	memmove(num, num+1, len-1);
	num[len-1] = tmp;
}

int main()
{
	int TT;
	scanf("%d",&TT);
	for (int tt = 1; tt <= TT; tt++)
	{
		printf("Case #%d: ", tt);
		scanf("%s%s",A,B);
		length = strlen(A);

		int ans = 0;

		while (strcmp(A, B) <= 0)
		{
			set<string> dupled;
			memcpy(C, A, length + 1);
			for (int i = 0; i < length - 1; i++)
			{
				rotate(C, length);
				if (strcmp(C, A) > 0 && strcmp(C, B) <= 0 && dupled.find(C) == dupled.end())
				{
					ans++;
					dupled.insert(C);
				}
			}
			if (increase(A, length) == false) break;
		}
		printf("%d\n", ans);
	}
	return 0;

	return 0;
}