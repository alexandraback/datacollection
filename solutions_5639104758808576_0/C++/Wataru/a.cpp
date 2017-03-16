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

int k;
string s;


void Load()
{
	cin >> k >> s;
}

void Solve()
{
	int i;
	int ans = 0;
	int total = 0;
	for (i = 0; i <= k; i++) {
		int cur = (int)s[i] - (int)'0';
		if (cur > 0) {
			if (total < i) {
				ans += i-total;
				total = i;
			}
			total += cur;
		}
	}
	cout << ans << "\n";
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
