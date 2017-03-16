
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
 #include<stdio.h>
using namespace std;
int main() {
	freopen("A-large (4).in", "r", stdin);
	freopen("a.out", "w", stdout);
 
	long long int t, r, c, w;
	cin >> t;
	for (long long int i = 0; i<t; i++)
	{
		long long int xx = 0;
		cin >> r >> c >> w;
		xx = c / w *r;
		xx += w - 1;
		if (c%w != 0)
			xx++;
		cout << "Case #" << i + 1 << ": " << xx << endl;
	}
 
	return 0;
}
