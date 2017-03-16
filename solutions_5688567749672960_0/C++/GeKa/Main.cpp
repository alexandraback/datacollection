#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <memory.h>


using namespace std;

long long rev(long long a)
{
	long long res = 0;
	while (a)
	{
		res = res * 10 + a%10;
		a/=10;
	}
	return res;
}

#define MAX 1000010
int mas[MAX];

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	cin >> T;
	mas[1] = 1;
	for (int i = 2;  i < MAX; i++)
		mas[i] = 1000000000;
	for (int i = 1; i+1 < MAX; i++)
	{
		mas[i+1] = min(mas[i] + 1, mas[i+1]);
		int a = rev(i);
		if (a > i && a < MAX)
			mas[a] = min(mas[i] + 1, mas[a]);
	}

	for (int t = 0; t < T; t++)
	{
		long long N;
		cin >> N;
		
		
		printf("Case #%d: %d\n", t+1, mas[N]);
	}

	return 0;
}