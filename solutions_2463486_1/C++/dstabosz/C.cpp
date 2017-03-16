#include <cstdio>
#include <string.h>
#include <set>

#include <cassert>

using namespace std;

#define DEBUG 0
#define TEST 0

bool IsFair (long long n)
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

  set<long long> all;

  fgets(buf, 255, stdin);

  int T;
  sscanf(buf, "%d", &T);

	long long n = 1;
	long long count = 0;

	while (1)
	{
		if (n*n > 100000000000000LL)
			break;

		if (IsFair(n*n) && (IsFair(n)))
		{
		  count++;

	//	  printf("\n|%lld %lld|\n", n, n*n);
		  all.insert(n*n);
		}
	
		n++;
    }	

//  printf("List complete, %d items\n", all.size());

#if TEST
  T = 10000;
#endif

  for (int i = 1; i <= T; i++)
  {
    long long A, B;
	long long count = 0;
#if !TEST
	printf("Case #%d: ", i);
	fgets(buf, 255, stdin);
	assert(sscanf(buf, "%lld %lld", &A, &B) == 2);
#else
	A = 1;
	B = 100000000000000;
#endif

    for (set<long long>::iterator iter = all.begin(); iter != all.end(); iter++)
    {
	  if (*iter < A)
		  continue;
	  if (*iter > B)
		  break;
	  count++;
    }
#if !TEST
	printf("%d\n", count);
#else
	assert(count == 39);
#endif
  }
}