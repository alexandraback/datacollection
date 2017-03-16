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



int k, c, s;

void Load()
{
	 cin >> k >> c >> s;
}

void Solve()
{
	if (c == 1) {
		if (s < k) cout << "IMPOSSIBLE\n";
		else {
			for (int i = 1; i <= k; i++) cout << i << " ";
			cout << "\n";
		}
	} else {
		if (s < k-1) cout << "IMPOSSIBLE\n";
		else {
			int z =2;
			if (k == 1) z = 1;
			for (int i = z; i <= k; i++) cout << i << " ";
			cout << "\n";
		}
	}
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
