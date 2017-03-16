#include <iostream>
#include <cstddef>
#include <cstdio>
#include <unordered_set>
#include <set>


#pragma warning(disable : 4996)

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	size_t __; cin >> __;
	for (size_t _ = 0; _ < __; ++_) {
		size_t c, d, v;
		cin >> c >> d >> v;
		vector<size_t> t(d);
		vector<bool> b(v + 1);
		auto check = [&]() -> size_t {
			for (size_t i = 1; i < (1u << t.size()); ++i) {
				size_t x = 0;
				for (size_t j = 0; j < t.size(); ++j) {
					if ((1 << j) & i)
						x += t[j];
				}
				if (x < b.size())
					b[x] = true;
			}
			for (size_t i = 1; i < b.size(); ++i) {
				if (!b[i])
					return i;
			}
			return ~0u;
		};
		size_t x;
		while ((x = check()) < b.size())
			t.push_back(x);
		cout << "Case #" << (_ + 1) << ": " << t.size() - d << endl;
	}
	return 0;
}