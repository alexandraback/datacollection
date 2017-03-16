#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

typedef unsigned long long uint64;

struct Data
{
	long long d, n, w, e, s, dd, dp, ds;
};

struct Attack
{
	long long d, w, e, s;
	bool operator<(const Attack &a) const {
		return d < a.d;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	int test_cases;
	cin >> test_cases;
	for (int test_num = 1; test_num <= test_cases; ++test_num) {
		cout << "Case #" << test_num << ": ";
		int N;
		long long res = 0;
		cin >> N;
		vector<Data> v(N);
		for (auto &i : v)
			cin >> i.d >> i.n >> i.w >> i.e >> i.s >> i.dd >> i.dp >> i.ds;
		vector<Attack> a;
		Attack t;
		for (auto &i : v) {
			for (long long k = 0; k < i.n; ++k) {
				t.d = i.d + k * i.dd;
				t.w = i.w + k * i.dp;
				t.e = i.e + k * i.dp;
				t.s = i.s + k * i.ds;
				a.push_back(t);
			}
		}
		sort(a.begin(), a.end());
		unordered_map<long long, long long> m;
		for (unsigned i = 0; i < a.size(); ++i) {
			unsigned j = i;
			for (; j < a.size() && a[i].d == a[j].d; ++j);
			for (unsigned k = i; k < j; ++k) {
				for (long long p = a[k].w; p < a[k].e; ++p)
					if (m[p] < a[k].s) {
						++res;
						break;
					}
			}
			for (unsigned k = i; k < j; ++k)
				for (long long p = a[k].w; p < a[k].e; ++p)
					if (m[p] < a[k].s)
						m[p] = a[k].s;
		}
		cout << res << endl;
	}
	return 0;
}