#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vp;

const int MAX = 6;

int e[MAX];


int b = 0;
long long m = 0;

int check(int from)
{
	if (from == b - 1)
		return 1;
	int cnt = 0;
	for (int i = from + 1; i < b; ++i)
	{
		if (e[from] & (1 << b - i - 1))
		{
			// cout << "+" << endl;
			cnt += check(i);
		}
	}
	// cout << "from " << from << " cnt " << cnt << endl;
	return cnt;
}

void solve()
{
	cin >> b;
	cin >> m;

	int pos = b * (b - 1) / 2;
	int cnt = 1 << pos;


	int i = 0;
	for (i = 0; i < cnt; ++i)
	{
		int curr = i;
		// cout << "curr " << curr << endl;
		for (int j = 0; j < b; ++j)
			e[j] = 0;
		for (int j = 0; j < b - 1; ++j)
		{
			// cout << "j " << j << endl;
			for (int p = 0; p < b - j - 1; ++p)
			{
				int bit = (curr & 1);
				// cout << "here " << bit << endl;
				e[j] <<= 1;
				if (bit)
					e[j] |= 1;
				// cout << "there " << e[j] << endl;
				curr >>= 1;
			}
		}
		// cout << endl;
		// for (int j = 0; j < b; ++j)
		// 	cout << e[j] << endl;

		// for (int j = 0; j < b; ++j)
		// {
		// 	for (int k = 0; k < b; ++k)
		// 		cout << (char)('0' + !!(e[j] & (1 << b - k - 1)));
		// 	cout << endl;
		// }

		if (check(0) == m)
		{
			cout << "POSSIBLE" << endl;
			for (int j = 0; j < b; ++j)
			{
				for (int k = 0; k < b; ++k)
					cout << (char)('0' + !!(e[j] & (1 << b - k - 1)));
				cout << endl;
			}
			break;
		}
	}
	if (i == cnt)
	{
		cout << "IMPOSSIBLE" << endl;
	}
}

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return 0;
}
