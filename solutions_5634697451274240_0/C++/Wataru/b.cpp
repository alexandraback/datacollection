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


string s;

void Load()
{
	cin >> s;
}

void Solve()
{
	int i, j;
	int n = s.length();
	j = 0;
	char c0, c1;
	c0 = s[0];
	c1 = s[n-1];
	for (i = 0; i < n; i++) {
		if (i == 0 || s[i-1] != s[i]) j++;
	}
	if (c1 == '+') j--;
	cout << j << "\n";
}

int main()
{
	cout.setf(ios::fixed|ios::showpoint);
	cout.precision(10);
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		Solve(); 
	}
	return 0;
}
