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


int n;

void Load()
{
	cin >> n;
}

void Solve()
{
	if (n == 0) {
		cout << "INSOMNIA\n";
		return;
	}
	long long i = n;
	bool seen[10];
	memset(seen, 0, sizeof(seen));
	int left = 10;
	while (true) {
		int j = i;
		while (j > 0) {
			int k = j % 10;
			j /= 10;
			if (!seen[k]) {
				seen[k] = true;
				left--;
				if (left == 0) break;
			}
		}
		if (left == 0) break;
		i += n;
	}
	cout << i << "\n";
}

int main()
{
	cout.setf(ios::fixed|ios::showpoint);
	cout.precision(10);
	int nt, tt;
	    /*
	for (n = 1; n < 1000000; n++) {
		cout << n << " ";
		Solve();
	}
	      */
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		Solve(); 
	}
	return 0;
}
