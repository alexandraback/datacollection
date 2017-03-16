#include <iostream>
#include <utility>

using namespace std;

int main()
{
	int cn; cin >> cn;
	for (int cc=1; cc<=cn; cc++)
	{
		int n, x, y;
		cin >> n >> x >> y;
		if (x > y) swap(x, y);
		cout << "Case #" << cc << ": ";
		if (x * y % n == 0
			&& x >= n-1)
			cout << "GABRIEL" << endl;
		else
			cout << "RICHARD" << endl;
	}
	return 0;
}
