#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
 #include<stdio.h>
using namespace std;


int main() {
	freopen("niki.in", "r", stdin);
	freopen("niki.out", "w", stdout);
 
	int test, r, c, w;
	cin >> test;
	
	for (int ii = 0; ii<test; ii++)
	{
		int xx = 0;
		
		cin >> r >> c >> w;
     	xx = c / w *r;
 
		xx += w - 1;
		if (c%w != 0)
			xx++;
			
		cout << "Case #" << ii + 1 << ": " << xx << endl;
	}
 
	return 0;
}
