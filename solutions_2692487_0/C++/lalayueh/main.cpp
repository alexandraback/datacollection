#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <map>
typedef unsigned long long int LLU;
using namespace std;

LLU A;
LLU N;
LLU M[1000];

void input()
{
	scanf("%llu %llu", &A, &N);
	for (int i = 0 ; i < N ; i++)
		scanf("%llu", &M[i]);

	sort(M, M + N);
}

int solve(int index, int value, int result)
{
	for (int i = index ; i < N ; i++) {
		if (value > M[i]) {
			value = value + M[i];
		} else if (value == 1) {
			result++;
		} else {
			return min(solve(i + 1, value, result + 1), solve(i, value + value - 1, result + 1));
		}
	}

	return result;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d\n", &n);
	for (int i = 0 ; i < n ; i++) {
		input();
		printf("Case #%d: %d\n", i + 1, solve(0, A, 0));
	}

	return 0 ;
}