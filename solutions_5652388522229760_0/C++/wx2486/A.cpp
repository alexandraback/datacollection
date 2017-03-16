#include <iostream>
#include <cassert>

using namespace std;

int work(int n)
{
	bool in[10] = { false };
	int cnt = 0;

	for (int x = 1; x < 1000; x++)
	{
		for (int xn = x * n; xn; xn /= 10)
			if (in[xn % 10] == false)
			{
				in[xn % 10] = true;
				cnt++;
			}

		if (cnt == 10)
			return x * n;
	}

	assert(false);
}

int main()
{
	int cc, cn; cin >> cn;

	for (int cc = 1; cc <= cn; cc++)
	{
		int n; cin >> n;
		if (n == 0)
			cout << "Case #" << cc << ": INSOMNIA" << endl;
		else
			cout << "Case #" << cc << ": " << work(n) << endl;
	}

	return 0;
}