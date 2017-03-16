#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int cn; cin >> cn;
	for (int cc=1; cc<=cn; cc++)
	{
		int n; cin >> n;
		vector<int> v(n);
		for (int i=0; i<n; i++)
			cin >> v[i];
		int mint = 1000;
		for (int i=1; i<=1000; i++)
		{
			int cut = 0;
			for (int j=0; j<n; j++)
				cut += (v[j] - 1) / i;
			mint = min(mint, i + cut);
		}
		cout << "Case #" << cc << ": " << mint << endl;
	}

	return 0;
}
