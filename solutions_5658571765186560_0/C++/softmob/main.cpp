#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <set>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

void solve(int test)
{
	int64_t x, r, c;
	cin >> x >> r >> c;
	int id = 0;
	int64_t s = r * c;
	if (s % x != 0 || x >= 7)
	{
		id = 0;
	}
	else 
	{
		if (x <= 2)
			id = 1;
		else if (x == 3 && min(r, c) > 1)
			id = 1;
		else if (x == 4 && min(r, c) > 2)
			id = 1;		
	}
	string ans[] = {
		"RICHARD",
		"GABRIEL"
	};
	cout << "Case #" << test << ": " << ans[id] << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		solve(i+1);
	}
	return 0;
}