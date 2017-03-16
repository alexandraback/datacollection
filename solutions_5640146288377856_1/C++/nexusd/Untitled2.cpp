#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
 #include<stdio.h>
using namespace std;
int main() {
freopen("abc.txt","r",stdin);
	   freopen("pqr.txt","w",stdout);
 
	int t, bak, c, waka;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		int anserw = 0;
		cin >> bak >> c >> waka;
 
 
		anserw = c / waka *bak;
 
		anserw += waka - 1;
		if (c%waka != 0)
			anserw++;
		cout << "Case #" << i + 1 << ": " << anserw << endl;
	}
 
	return 0;
}
