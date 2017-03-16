#include <iostream>
#include <cstddef>
#include <cstdio>

#pragma warning(disable : 4996)

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	size_t __; cin >> __;
	for (size_t _ = 0; _ < __; ++_) {
		size_t r, c, w;
		cin >> r >> c >> w;
		cout << "Case #" << (_ + 1) << ": " << ((c / w) * r + (w - 1) + ((c % w) == 0 ? 0 : 1)) << endl;
	}
	return 0;
}