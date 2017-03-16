#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <utility>

using namespace std;

vector <int> pals;
vector <int> ans;


int get (int x) {
	int cnt = 0;
	for (int i = 0; i < ans.size(); i++)
		if (ans[i] <= x)
			cnt++;			
	return cnt;
}

bool ok (int x) {
	for (int i = 0; i < pals.size(); i++)
		if (pals[i] * pals[i] == x)
			return true;
	return false;	
}
                           

int main () {
                                     
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	vector <int> a, b;	
	for (int i = 1; i < 1000; i++) {
		a.clear();
		b.clear();
		int x = i;
		while (x) {
			a.push_back(x % 10);
			b.push_back(x % 10);
			x /= 10;
		}			
		reverse(b.begin(), b.end());
		int g = 1;
		for (int j = 0; j < a.size(); j++)
			if (b[j] != a[j])
				g = 0;
		if (g)
			pals.push_back(i);
		if (g && ok(i))
			ans.push_back(i);
	}
	int now = 0;
	while (t--) {
		int l, r;
		cin >> l >> r;
		printf("Case #%d: %d\n", ++now, get (r) - get (l - 1));
	}
	
	
	return 0;
}
