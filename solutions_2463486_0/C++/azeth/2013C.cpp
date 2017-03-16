// 2013C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
typedef long long int64;

const int psize = 10000002;

void process();
int test(int64 a, int64 b);
bool check(int num);
int64 isqrt(int64 num);

int array[psize];

int _tmain(int argc, _TCHAR* argv[])
{
	ios_base::sync_with_stdio(false);

	process();

	ifstream in("C.in");
	ofstream out("C.out");

	int t;
	in >> t;

	for (int c = 1; c <= t; c++) {
		int64 a, b;
		in >> a >> b;

		int res = test(a, b);
		out << "Case #" << c << ": " << res << endl;
	}

	return 0;
}

void process()
{
	for (int i = 1; i < psize; i++) {
		if (check(i)) {
			array[i] = array[i-1]+1;
		} else {
			array[i] = array[i-1];
		}
	}
}

int test(int64 a, int64 b)
{
	int64 left = isqrt(a);
	int64 right = isqrt(b);

	if (left*left == a) {
		left = left-1;
	}

	return array[right]-array[left];
}

bool check(int num)
{
	string str = to_string(num);
	for (int i = 0; i < str.size()/2; i++) {
		if (str[i] != str[str.size()-1-i]) {
			return false;
		}
	}

	int64 num2 = ((int64)num)*((int64)num);
	string str2 = to_string(num2);
	for (int i = 0; i < str2.size()/2; i++) {
		if (str2[i] != str2[str2.size()-1-i]) {
			return false;
		}
	}

	return true;
}

int64 isqrt(int64 num)
{
	int64 prev;
	int64 cur = num;

	do {
		prev = cur;
		cur = (prev + num/prev)/2;
	} while (prev > cur);

	return prev;
}