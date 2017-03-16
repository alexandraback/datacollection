#include <cassert>
#include <cstdio>
#include <vector>


const char * digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int tag_digit[10];
char tag_char[10];

void add(std::vector<int> & data, const char * s, int delta)
{
	for(int i = 0; s[i] != 0; i++)
		data[ s[i] ] += delta;
}

void prepare()
{
	std::vector<int> cnt(256, 0);
	for(int i = 0; i < 10; i++)
		add(cnt, digits[i], 1);

	std::vector<bool> used(10, false);
	for(int iter = 0; ; iter++)
	{
		int sum = 0;
		char next = 0;
		bool ok = false;
		for(char c = 'A'; c <= 'Z'; c++)
			if(cnt[c] > 0)
			{
				sum += cnt[c];
				if(cnt[c] == 1)
				{
					ok = true;
					next = c;
					break;
				}
			}
		
		if(sum == 0)
			break;

		assert(ok);
		
		int digit = -1;
		for(int i = 0; i < 10; i++)
		{
			if(used[i])
				continue;
				
			for(int j = 0; digits[i][j] != 0; j++)
				if(digits[i][j] == next)
				{
					digit = i;
					goto end;
				}
		}
		assert(false);
		end:;
		
		used[digit] = true;
		add(cnt, digits[digit], -1);

		tag_digit[iter] = digit;
		tag_char[iter] = next;
		//printf("%i: %c\n", digit, next);
	}
}

char s[1000000];

void solve()
{
	std::vector<int> r(10, 0);
	std::vector<int> count(256, 0);
	add(count, s, 1);

	for(int i = 0; i < 10; i++)
	{
		int c = count[ tag_char[i] ];
		int d = tag_digit[i];

		r[d] = c;
		add(count, digits[d], -c);
	}
	
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < r[i]; j++)
			printf("%i", i);
}

int main()
{
	prepare();
	
	int tests;
	scanf("%i\n", &tests);
	
	for(int test = 1; test <= tests; test++)
	{
		printf("Case #%i: ", test);
		scanf("%s\n", s);
		solve();
		printf("\n");
	}

	return 0;
}

