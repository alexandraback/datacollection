#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <iostream>
 
using namespace std;
 
 
 
int main() {
 
	int a,b,answer=0,t, r, c, w,d;
	cin >> t;
	for (int i = 1; i<=t; i++)
	{
		int res = 0;
		cin >> r >> c >> w;
 
 
		res = c / w *r;
 
		res += w - 1;
		if (c%w != 0)
			res++;
		cout << "Case #" << i << ": " << res << endl;
	}
 
	return 0;
}