#include <cstddef>
#include <iostream>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

bool can_richard_win(size_t x, size_t r, size_t c)
{
	//3 2 3
	if (x > max(r, c))
		return true;
	if (x >= (min(r, c) + 1) * 2 - 1)
		return true;
	if (r*c%x != 0)
		return true;
	if (r >= 3 && c >= 3) {
		if (x >= 5)
			return true;
	}
	else {
		if (x >= 4)
			return true;
	}
	return false;
}

int main()
{
	freopen("D-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	size_t cases; cin >> cases;
	for (size_t _ = 0; _ < cases; ++_) {
		size_t x, r, c;
		cin >> x >> r >> c;
		cout << "Case #" << (_ + 1) << ": " << (can_richard_win(x, r, c) ? "RICHARD" : "GABRIEL") << endl;
	}
	return 0;
}