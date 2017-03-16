#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>

using namespace std;

int n;
long long a[1000];

vector <pair<int, int> > sums;

void solve2(int testcase) {
	printf("Case #%d:\n", testcase);
	sums.clear();

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i < (1 << n); ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				sum += a[j];
			}
		}
		sums.push_back(make_pair(sum, i));
	}
	sort(sums.begin(), sums.end());

	for (int i = 1; i < sums.size(); ++i) {
		if (sums[i].first == sums[i - 1].first) {
			int val = sums[i].second;
			for (int j = 0; j < n; ++j) {
				if (val & (1 << j)) {
					printf("%d ", a[j]);
				}
			}
			printf("\n");
			val = sums[i - 1].second;
			for (int j = 0; j < n; ++j) {
				if (val & (1 << j)) {
					printf("%d ", a[j]);
				}
			}
			printf("\n");
			return ;
		}
	}
	printf("Impossible\n");
}

void solve(int testcase) {
	printf("Case #%d:\n", testcase);
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	random_shuffle(a, a + n);

	map <long long, int> mp;
	vector <vector <int> > res;

	int iter = 0;
	while (true) {
		set <int> st;
		while (st.size() < 10) {
			int x = rand() % 500;
			st.insert(x);
		}
		vector <int> current;
		long long sum = 0;
		for (set <int>::iterator it = st.begin(); it != st.end(); ++it) {
			current.push_back(*it);
			sum += a[*it];
		}
		res.push_back(current);
		if (mp.count(sum)) {
			int ind = mp[sum];
			for (int i = 0; i < 10; ++i) {
				cout << a[res[ind][i]];
				if (i != 9) printf(" ");
			}
			printf("\n");

			for (int i = 0; i < 10; ++i) {
				cout << a[current[i]];
				if (i != 9) printf(" ");
			}
			printf("\n");
			return;
		} else {
			mp[sum] = iter;
		}
		++iter;
	}
}

void generate() {
	printf("10\n");
	for (int i = 0; i < 10; ++i) {
		printf("500");
		for (int j = 0; j < 500; ++j) {
			cout << " ";
			cout << ((long long)rand() * (long long)rand() * (long long)rand()) % 1000000000000LL + 1;
		}
		cout << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	srand(123);

	int tests;

	cin >> tests;
	//generate();

	for (int t = 1; t <= tests; ++t) {
		solve(t);
		cerr << "Test " << t << endl;
	}

	return 0;
}