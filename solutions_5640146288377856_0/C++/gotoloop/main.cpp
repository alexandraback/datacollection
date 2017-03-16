#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int r, c, w;
		cin >> r >> c >> w;
		int k = (c - w) / w + 1;
		int o = r * k + w - 1 + (c % w == 0 ? 0 : 1);
		cout << "Case #" << i + 1 << ": " << o << endl;
	}
}
