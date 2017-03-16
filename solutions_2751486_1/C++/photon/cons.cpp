#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

char* name;
int spts[1000010];
int snum = 0;
int n;

int main()
{
	int t;
	scanf("%d", &t);

	for (int k = 0; k < t; k++)
	{

	unsigned long long int result = 0;
	snum = 0;
	name = new char[1000010];
	scanf("%s %d", name, &n);
	int len = strlen(name);

	int current = 0;
	for (int i = 0; i < len; i++)
	{
		if ((name[i] != 'a') &&
			(name[i] != 'e') &&
			(name[i] != 'i') &&
			(name[i] != 'o') &&
			(name[i] != 'u'))
		{
			current++;
			if (current >= n)
				spts[snum++] = i - n + 1;
		}
		else
		{
			current = 0;
		}
	}

	/*printf("snum = %d\n", snum);

	for (int i = 0; i < snum; i++)
	{
		printf("at %d\n", spts[i]);
	}*/

	if (snum  == 0) result = 0;
	else
	{
		current = 0;
		for (int i = 0; i <= spts[snum - 1]; i++)
		{
			if (i <= spts[current])
			{
				result += len - (spts[current] + n - 1);
				//printf("adding at i=%d : %d - %d\n", i, len, cons[current + n - 1]);
			}
			else
			{
				current++;
				result += len - (spts[current] + n - 1);
				//printf("adding at i=%d : %d - %d\n", i, len, cons[current + n - 1]);
			}
		}
	}

	//printf("Case #%d: %d\n", k+1, result);
	std::cout << "Case #" << k+1 << ": " << result << std::endl;
	}

	return 0;
}
