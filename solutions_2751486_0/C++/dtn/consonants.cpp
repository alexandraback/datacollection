
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
#define MIN(a, b) ((a > b) ? b : a)
#define MAX(a, b) ((a > b) ? a : b)

bool isconsonant(char c) {
	return (c != 'a' && c != 'e' && c != 'o' && c != 'i' && c != 'u');
}

int count(int p, int h, int n, int len, int c) {
	int l = h - c + 1;
	int a = (2 * (l - p) + c - n - 1) * (c - n) / 2;
	return ((h - n - p + 1) * (len - h) + a) ;
}

int nvalue(string &s, int n) {
	int p = -1;
	int total = 0;
	//int l = 0, h = 0;
	int len = s.length();
	int c = 0;
	for (int i = 0; i < len; i++) {
		if (isconsonant(s[i])) {
			c++;
			if (i == len - 1 && c >= n) {
				total += count(p, len-1, n, len, c);
				cout << i;
			}
		} else {
			if (c >= n) {
				total += count(p, i - 1, n, len, c);
				p = i - n;
			}
			c = 0;
		}
	}
	return total;
}

int main() {
	ifstream fi;
	ofstream fo;
	fi.open("in.in");
	fo.open("out.txt");

	int t;
	fi >> t;
	for (int c = 1; c <= t; c++) {
		string s;
		int n;
		fi >> s >> n;
		//cout << s << n << endl;
		fo << "Case #" << c << ": " << nvalue(s, n) <<"\n";
	}

	fo.close();
	fi.close();
	return 0;
}
