#include <stdio.h>
#include <string.h>


inline bool isVowel(const char& a)
{
	return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

int main()
{
	char buf[1000005];

	int ile,n;
	scanf("%d\n", &ile);
	for(int i = 1 ; i <= ile ; ++i)
	{
		scanf("%s %d\n", buf, &n);
		int size = strlen(buf);

		int row = 0;
		unsigned long long res = 0;
		int previous = 0;
		for(int j = 0 ; j < size ; ++j)
		{
			if(isVowel(buf[j]))
			{
				row = 0;
				continue;
			}

			++row;
			if(row >= n)
			{
                res += (j+2-n-previous)*(size-j);
                previous = j+2-n;
			}
		}

		printf("Case #%d: %llu\n", i, res);

	}
	return 0;
}
