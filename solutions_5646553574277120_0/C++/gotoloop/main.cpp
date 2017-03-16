#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		int c, d, v;
		cin >> c >> d >> v;
		vector<int> vv;
		for (int i = 0; i < d; i++)
		{
			int w;
			cin >> w;
			vv.push_back(w);
		}
		vv.push_back(v + 1);
		sort(vv.begin(), vv.end());
		int nw = 0;
		int kw = 0;
		for (int i = 0; i < d + 1; i++)
		{
			while (1)
			{
				if (vv[i] <= kw + 1)
				{
					kw += vv[i];
					break;
				}
				else
				{
					kw += kw + 1;
					nw++;
				}
			}
		}
		cout << "Case #" << q + 1 << ": " << nw << endl;
	}
}