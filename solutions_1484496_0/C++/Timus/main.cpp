#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int> > z;

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int tests;

	int all = (1 << 20) - 1;

	cin >> tests;
	for (int testnum = 1; testnum <= tests; ++testnum) {
		int n;
		cin >> n;
		vector<int> a;
		a.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		bool can = false;
		cerr << testnum << endl;
		printf("Case #%d:\n", testnum);
		for (int mask = 1; mask < (1<<20); ++mask) {
			int sum = 0;
			for (int i = 0; i < n; ++i)
				if ((1<<i)&mask)
					sum += a[i];
			int m = all ^ mask;
			for (int s = m; s; s = (s - 1)&m) {
				int tmp = 0;
				for (int i = 0; i < n; ++i)
					if ((1<<i)&s)
						tmp += a[i];
				if (tmp == sum) {
					for (int i = 0; i < n; ++i)
						if ((1<<i)&mask)
							printf("%d ", a[i]);
					printf("\n");
					for (int i = 0; i < n; ++i)
						if ((1<<i)&s)
							printf("%d ", a[i]);
					printf("\n");
					can = true;
					break;
				}
			}
			if (can)
				break;
		}
		if (!can)
			printf("Impossible\n");
	}
	return 0;
}
