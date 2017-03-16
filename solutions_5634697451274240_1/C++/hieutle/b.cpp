#include <string.h>
#include <stdio.h>
#include <iostream>
// #define TEST

using namespace std;
const int MAX_LEN = 105;
char stack[MAX_LEN];
char cakes[2] = {'+', '-'};

int countFlips(int begin, int end, int target)
{
	if (begin == end)
		return (stack[begin] == cakes[target]) ? 0 : 1;
	if (stack[end] == cakes[target]) {
		return countFlips(begin, end - 1, target);
	} else {
		return 1 + countFlips(begin, end - 1, 1 - target);
	}
}

int main()
{
	#ifndef TEST
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin >> stack;
		int length = strlen(stack);
		int res = countFlips(0, length - 1, 0);
		cout << "Case #" << tt << ": " << res << endl;
	}
}



