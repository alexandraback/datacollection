#include <iostream>

using namespace std;

int t, r, c, w;

int main ()
{
	cin >> t;
	for (int i = 0; i ++< t;) {
		cin >> r >> c >> w;
		int a = (c + w - 1) / w + w - 1;
		cout << "Case #" << i << ": " << a << '\n';
	}
}

