/*Close Match*/

#include<cstdio>
#include<string>
#include<climits>

using namespace std;

long long min_diff, min_n1, min_n2;

void find_min_scores(const string &, const string &, long long, long long, unsigned int, unsigned int);
string convert_to_string(long long, unsigned int);

int main()
{
	char str[25];
	int t, T;
	unsigned int length;
	string C, J, num1, num2;
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%s", str);
		C = string(str);
		scanf("%s", str);
		J = string(str);
		min_diff = LLONG_MAX;
		min_n1 = 0;
		min_n2 = LLONG_MAX;
		length = C.length();
		find_min_scores(C, J, 0, 0, 0, length);
		num1 = convert_to_string(min_n1, length);
		num2 = convert_to_string(min_n2, length);
		printf("Case #%d: %s %s\n", t, num1.c_str(), num2.c_str());
	}
	return 0;
}

void find_min_scores(const string &num1, const string &num2, long long n1, long long n2, unsigned int index, unsigned int length)
{
	int i, j;
	if (index == length)
	{
		if (min_diff > abs(n1 - n2))
		{
			min_diff = abs(n1 - n2);
			min_n1 = n1;
			min_n2 = n2;
		}
		else if (min_diff == abs(n1 - n2))
		{
			if (min_n1 > n1)
			{
				min_n1 = n1;
				min_n2 = n2;
			}
			else if (min_n1 == n1)
			{
				if (min_n2 > n2)
					min_n2 = n2;
			}
		}
		return;
	}
	if ((num1[index] == '?') && (num2[index] == '?'))
		for (i = 0; i <= 9; i++)
			for (j = 0; j <= 9; j++)
				find_min_scores(num1, num2, n1 * 10 + i, n2 * 10 + j, index + 1, length);
	else if (num1[index] == '?')
		for (i = 0; i <= 9; i++)
			find_min_scores(num1, num2, n1 * 10 + i, n2 * 10 + (num2[index] - '0'), index + 1, length);
	else if (num2[index] == '?')
		for (j = 0; j <= 9; j++)
			find_min_scores(num1, num2, n1 * 10 + (num1[index] - '0'), n2 * 10 + j, index + 1, length);
	else
		find_min_scores(num1, num2, n1 * 10 + (num1[index] - '0'), n2 * 10 + (num2[index] - '0'), index + 1, length);
}

string convert_to_string(long long n, unsigned int length)
{
	string dig[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	string num;
	while (n > 0)
	{
		num = dig[n % 10] + num;
		n /= 10;
	}
	while (num.length() < length)
		num = "0" + num;
	return num;
}