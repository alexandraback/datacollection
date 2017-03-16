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

LLU t, r;
void input()
{
	scanf("%llu %llu", &r, &t);
}

bool check_val(LLU x)
{
	LLU val = (2 * x - 1 + 2 * r); 
	if (val <= t/x) {
		return true;
	} else {
		return false;
	}
}

LLU solve()
{
	LLU first = 0;
	LLU last = (1ULL << 62) - 1;
	LLU middle = (first + last + 1) / 2;
	while (first < last) {
		if (check_val(middle)) {
			first = middle;
		} else {
			last = middle - 1;
		}
		middle = (first + last + 1) / 2;
	}
	return last;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d\n", &n);
	for (int i = 0 ; i < n ; i++) {
		input();
		printf("Case #%d: %llu\n", i + 1, solve());
	}

	return 0 ;
}