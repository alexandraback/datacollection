// fbhc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// fbhc.cpp : Defines the entry point for the console application.
//



#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<limits>
#include<climits>
#include<cmath>
#include<functional>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<typeinfo>
using namespace std;

typedef long long int ll;
typedef short int i16;
typedef unsigned long long int u64;
typedef unsigned int u32;
typedef unsigned short int u16;
typedef unsigned char u8;

string u[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };


int foo(string s) {

	int num = 0;
	for (int i = 0; i < s.length(); i++) {

		num += pow(10, s.length() - i - 1) * (s[i] - '0');
	}
	return num;
}
int l;
int min_diff = INT_MAX;
int min_a = INT_MAX;
string ac, bc;
int min_b = INT_MAX;
void solve(string a, string b, int idx) {

	//cout << a << " " << b << endl;
	if (idx == l) {
		//cout << a << " " << b << endl;
		int z = abs(foo(a) - foo(b));
		if (z < min_diff) {

			min_diff = z;
			min_a = foo(a);
			ac = a;
			bc = b;
			min_b = foo(b);
		}
		else if (z == min_diff) {

			if (min_a > foo(a)) {
				min_a = foo(a);
				ac = a, bc = b;
				min_b = foo(b);
			}
			else if (min_a == foo(a) && min_b > foo(b)) {
				bc = b;
				min_b = foo(b);
			}
		}
		return;
	}


	if (a[idx] != '?' && b[idx] != '?') {

		solve(a, b, idx + 1);
	}

	else if (a[idx] == '?' && b[idx] == '?') {

		for (char i = '0'; i <= '9'; i++) {
			for (char j = '0'; j <= '9'; j++) {
				string aa = a, bb = b;
				aa[idx] = i, bb[idx] = j;
				solve(aa, bb, idx + 1);
			}
		}
	}
	else if (a[idx] != '?' && b[idx] == '?') {

		
			for (char j = '0'; j <= '9'; j++) {
				string bb = b;
				bb[idx] = j;
				solve(a , bb , idx + 1);
			}
		
	}
	else {

		
			for (char j = '0'; j <= '9'; j++) {
				string aa = a;
				aa[idx] = j;
				solve(aa , b, idx + 1);
			}
		
	}

}
int maint()
{
	ofstream cout("out.txt");
	ifstream cin("e.in");

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {

		string c, j;
		cin >> c >> j;
	 l = c.length();
	 min_diff = INT_MAX;
	 min_a = INT_MAX;
	 //string ac, bc;
	 min_b = INT_MAX;

	   solve(c, j, 0);
		
		cout << "Case #" << tc << ": ";
		cout << ac<< " " << bc ;

		cout << '\n';
	}

	return 0;
}




int _tmain(int argc, _TCHAR* argv[])
{
	return maint();
	return 0;
}

