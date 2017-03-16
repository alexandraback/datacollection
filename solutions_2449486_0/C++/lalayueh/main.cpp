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
using namespace std;

int XMAX[101];
int YMAX[101];
int LAWN[101][101];
int X, Y;

void input()
{
	scanf("%d %d", &X, &Y);
	for (int i = 0 ; i < X ; i++) {
		for (int j = 0 ; j < Y ; j++) {
			scanf("%d", &LAWN[i][j]);
		}
	}

	// XMAX
	for (int i = 0 ; i < X ; i++) {
		int max_ = INT_MIN;
		for (int j = 0 ; j < Y ; j++) {
			max_ = max(max_, LAWN[i][j]);
		}
		XMAX[i] = max_;
	}
	// YMAX
	for (int i = 0 ; i < Y ; i++) {
		int max_ = INT_MIN;
		for (int j = 0 ; j < X ; j++) {
			max_ = max(max_, LAWN[j][i]);
		}
		YMAX[i] = max_;
	}
}

bool solve()
{
	for (int i = 0 ; i < X ; i++) {
		for (int j = 0 ; j < Y ; j++) {
			// check
			int val = LAWN[i][j]; 
			if (val < XMAX[i] && val < YMAX[j]) {
				return false;
			}
		}
	}

	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d\n", &n);
	for (int i = 0 ; i < n ; i++) {
		input();
		printf("Case #%d: %s\n", i + 1, solve() ? "YES" : "NO");
	}

	return 0 ;
}