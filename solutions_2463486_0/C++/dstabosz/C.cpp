#include <cstdio>
#include <string.h>

#include <cassert>

#define DEBUG 0

bool IsFair (int n)
{
	int digits[100];

	int i = 0;
#if DEBUG
	printf("IsFair %d\n", n);
#endif
	while (n != 0)
	{
		digits[i] = n % 10;
		n = n / 10;
		i++;
	}

	i--;

	for (int j = 0; j < i; j++)
	{
#if DEBUG
		printf ("%d =? %d\n", digits[j], digits[i]);
#endif
		if (digits[i] != digits[j])
		{
			return false;
		}
		i--;
	}

	return true;
}

int main(int argc, char *argv[])
{
  char buf[255];

  fgets(buf, 255, stdin);

  int T;
  sscanf(buf, "%d", &T);

  for (int i = 1; i <= T; i++)
  {
	int A, B;
    printf("Case #%d: ", i);
	fgets(buf, 255, stdin);
	assert(sscanf(buf, "%d %d", &A, &B) == 2);
#if DEBUG
	  printf("%d %d\n", A, B);
#endif
	int n = 1;
	int count = 0;

	while (1)
	{
		if (n*n < A)
		{
			n++;
			continue;
		}
		if (n*n > B)
			break;

		if (IsFair(n*n) && (IsFair(n)))
		{
		  count++;
#if DEBUG
		  printf("\n|%d %d|\n", n, n*n);
#endif
		}
	
		n++;
	}
	printf("%d\n", count);
  }	


}