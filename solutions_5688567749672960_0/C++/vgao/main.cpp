#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <cstdio>

#pragma warning(disable : 4996)

using namespace std;

typedef unsigned long long ull;

template <class T>
T reverse(T x)
{
	static vector<T> v;
	v.clear();
	do {
		v.push_back(x % 10);
		x /= 10;
	} while (x);
	T r = 0;
	for (auto x : v)
		r = r * 10 + x;
	return r;
}

struct status
{
	ull v;
	size_t s;

	bool operator < (const status & t) const
	{
		if (s != t.s)
			return s < t.s;
		return v > t.v;
	}

	status(ull v, size_t s) :
		v(v), s(s)
	{
	}
};

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	vector<size_t> v(1000000 + 1, numeric_limits<size_t>::max());
	v[1] = 1;
	for (size_t i = 1; i + 1 < v.size(); ++i) {
		v[i + 1] = min(v[i + 1], v[i] + 1);
		auto j = reverse(i);
		if (j < v.size())
			v[j] = min(v[j], v[i] + 1);
	}
	size_t cases; cin >> cases;
	for (size_t _ = 0; _ < cases; ++_) {
		ull n; cin >> n;
		cout << "Case #" << (_ + 1) << ": " << v[n] << endl;
	}
	return 0;
}