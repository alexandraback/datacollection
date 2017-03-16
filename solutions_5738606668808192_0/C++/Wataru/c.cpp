#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


int n, k;



void Load()
{
	cin >> n >> k;
}

string Binary(long long x, int sz) {
	string t(sz, '0');
	int i = sz-1;
	while (x > 0) {
		t[i--] = (char)((int)'0'+(x % 2));
		x /= 2;
	}
	return t;
}

long long Interprete(string t, int base, int sz) {
	long long ans = 0;
	long long b = 1;
	for (int i = sz-1; i >= 0; i--) {
		if (t[i] == '1') ans += b;
		b *= base;
	}
	return ans;
}


void Generate(int bl, int sz)
{
	long long i;
	long long M = (1 << (long long)sz) - 1;
	i = 1 + (1 << ((long long)sz-1));
	while(true) {
		if (k-- == 0) break;
		string t = Binary(i, sz);
		int j;
		for (j = 0; j < bl; j++)
			cout << t;
		for (j = 2; j <= 10; j++) {
			cout << " " << Interprete(t, j, sz);
		}
		cout << "\n";
		if (i == M) break;
		i += 2;
	}

}


void Solve()
{
	int bl = 8;
	if (n == 16) bl = 8;
	else if (n == 32) bl = 16;
	else if (n == 6) bl = 3;
	Generate(n / bl, bl);
}

int main()
{
	cout.setf(ios::fixed|ios::showpoint);
	cout.precision(10);
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ":\n";
		Load();
		Solve(); 
	}
	return 0;
}
