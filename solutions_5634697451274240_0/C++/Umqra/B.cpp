#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

int solve(string str)
{
	int start = 0;
	int cnt = 0;
	for (int i = 1; i < (int)str.length(); i++)
	{
		if (str[i] != str[start])
		{
			cnt++;
			start = i;
		}
	}
	if (str.back() == '+')
		cnt--;
	return cnt + 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		string str;
		cin >> str;
		printf("Case #%d: ", i + 1);
		printf("%d\n", solve(str));
	}
	return 0;
}
