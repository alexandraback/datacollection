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
vector<int> a;

void Load()
{
	cin >> n;
	int i;
	a.resize(n);
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
}




void Solve()
{
	multiset<int> q;
	int i;
	int cur;
	int steps = 0;
	int ans = a[n-1];
	for (i = 1; i < a[n-1]; i++) {
		int j;
		steps = 0;
		for (j = 0; j < n; j++) {
			steps += ((a[j]-1) / i);
		}
		cur = steps + i;
		if (cur < ans)
			ans = cur;
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
