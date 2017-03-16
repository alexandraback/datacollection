#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAX_N = 2020;

char st[MAX_N];
int letter_num[30];
int ans[10];
char number[10][10] = {"ZERO", "EIGHT", "THREE", "TWO", "FOUR", "FIVE", "SIX", "SEVEN", "ONE", "NINE"};
int link[10] = {0, 8, 3, 2, 4, 5, 6, 7, 1, 9};

int get_min_num(char *st)
{
	int ret = MAX_N;
	for (int i = 0; st[i]; i++)
	{
		ret = min(ret, letter_num[st[i] - 'A']);
	}
	return ret;
}

void reduce(char * st, int delta)
{
	for (int i = 0; st[i]; i++)
	{
		letter_num[st[i] - 'A'] -= delta;
	}
}

void work()
{
	memset(letter_num, 0, sizeof(letter_num));
	for (int i = 0; st[i]; i++)
	{
		letter_num[st[i] - 'A']++;
	}

	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < 10; i++)
	{
		int num = get_min_num(number[i]);
		reduce(number[i], num);
		ans[link[i]] = num;
	}
}

void output()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < ans[i]; j++)
		{
			putchar(i + '0');
		}
	}
	putchar('\n');
}

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d: ", case_num);
		scanf("%s", st);
		work();
		output();
	}
	return 0;
}
