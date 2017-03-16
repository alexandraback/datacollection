#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	int t;
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		ll c, d, v;
		cin >> c >> d >> v;
		vector<ll> vv;
		for (int i = 0; i < d; i++)
		{
			ll w;
			cin >> w;
			vv.push_back(w);
		}
		vv.push_back(v + 1);
		sort(vv.begin(), vv.end());
		ll nw = 0;
		ll kw = 0;
		for (int i = 0; i < d + 1; i++)
		{
			while (1)
			{
				if (vv[i] <= kw + 1)
				{
					kw += vv[i] * c;
					break;
				}
				else
				{
					kw += (kw + 1) * c;
					nw++;
				}
			}
		}
		cout << "Case #" << q + 1 << ": " << nw << endl;
	}
}