#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
 #include<stdio.h>
using namespace std;
int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
 
	int t, r, c, w;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		int xx = 0;
		cin >> r >> c >> w;
 
 
		xx = c / w *r;
 
		xx += w - 1;
		if (c%w != 0)
			xx++;
		cout << "Case #" << i + 1 << ": " << xx << endl;
	}
 
	return 0;
}
