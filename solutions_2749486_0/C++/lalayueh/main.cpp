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
typedef long long int LLI;
using namespace std;

LLI X;
LLI Y;

void input()
{
	cin >> X >> Y;
}

string solve()
{
	string result;
	if (X > 0) {
		for (LLI i = 0 ; i < X ; i++) {
			result.push_back('W');
			result.push_back('E');
		}
	} else {
		X = -1 * X;
		for (LLI i = 0 ; i < X ; i++) {
			result.push_back('E');
			result.push_back('W');
		}
	}

	if (Y > 0) {
		for (LLI i = 0 ; i < Y ; i++) {
			result.push_back('S');
			result.push_back('N');
		}
	} else {
		Y = -1 * Y;
		for (LLI i = 0 ; i < Y ; i++) {
			result.push_back('N');
			result.push_back('S');
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
		printf("Case #%d: %s\n", i + 1, solve().c_str());
	}

	return 0 ;
}