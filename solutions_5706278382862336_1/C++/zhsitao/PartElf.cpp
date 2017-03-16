#define IOSTREAM_TO_FSTREAM

#include<iostream>
#include<string.h>
#ifdef IOSTREAM_TO_FSTREAM
#include<fstream>
#endif

using namespace std;

long long myatoi(const char *s) {
	long long r = 0;
	int i = 0;
	while (i < strlen(s)) {
		r *= 10;
		r += s[i] - '0';
		i++;
	}
	return r;
}

long long gcd(long long a, long long b) {
	long long r;
	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

bool check(long long &a, long long &b) {
	long long c = gcd(a, b);
	a /= c;
	b /= c;
	long long t = 1;
	for (int i = 0 ; i < 40 ; i++) {
		t *= 2;
		if (t == b) {
			return true;
		}
	}
	return false;
}

int main()
{
#ifdef IOSTREAM_TO_FSTREAM
	ifstream fin;
	fin.open("A-large.in");
	cin.rdbuf(fin.rdbuf());
	ofstream fout;
	fout.open("A-large.out");
	cout.rdbuf(fout.rdbuf());
#endif
	int n0;
	char c[100];
	cin >> n0;
	for (int i0 = 1 ; i0 <= n0 ; i0++) {
		cin >> c;
		long long a, b;
		for (int i = 0 ; i < strlen(c) ; i++) {
			if (c[i] == '/') {
				char c1[20] = {0}, c2[20] = {0};
				strncpy(c1, c, i);
				strncpy(c2, c + i + 1, strlen(c) - i);
				a = myatoi(c1);
				b = myatoi(c2);
				break;
			}
		}
		cout << "Case #" << i0 << ": ";
		//cout << a << "/" << b << endl;
		if (check(a, b)) {
			int r = 1;
			while (b >= 2) {
				if (a * 2 >= b) {
					break;
				} else {
					r++;
					b /= 2;
				}
			}
			cout << r << endl;
			continue;
		}
		cout << "impossible" << endl;
	}
	return 0;
}
