#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int powers[10];
	powers[0] = 1;
	for (int i = 1; i <= 9; ++i)
		powers[i] = powers[i - 1] * 10;
	int t = 0;
	cin >> t; getchar();
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ": ";
		int a, b;
		cin >> a >> b;
		int temp = a, len = 0;
		while (temp > 0)
		{
			temp /= 10;
			++len;
		}
		vector<pair<int, int>> vect;
		for (int i = a; i <= b; ++i)
			for (int j = 1; j < len; ++j)
			{
				int res = (i % powers[j]) * powers[len - j] + i / powers[j];
				if (i < res && res <= b)
					vect.push_back(make_pair(i, res));
			}
		__int64 ans = 0;
		sort(vect.begin(), vect.end());
		for (int i = 0; i < vect.size(); ++i)
			if (i == 0 || vect[i] != vect[i - 1])
				++ans;
		cout << ans << endl;
	}
}