#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t, a, n;

	cin >> t;

	for(int j=0;j<t;j++)
	{
		cin >> a >> n;

		vector<int> m(n);

		for(int i=0;i<n;i++)
			cin >> m[i];
		sort(m.begin(), m.end());

		int i = 0;
		int c = 0;
		while (i<n)
		{
			if (c >= n)
			{
				c = n;
				break;
			}
			if (a > m[i])
			{
				a += m[i];
				i++;
				continue;
			}
			if (i == m.size()-1)
			{
				c++;
				if (c >= n)
				{
					c = n;
				}
				break;
			}
			if(a == 1)
			{
				i++;
				c++;
				continue;
			}
			c++;
			a += a-1;
		}

		cout << "Case #" << j+1 << ": " << c << endl;

		/*for(int i=0;i<n;i++)
			cout << m[i] << " ";
		cout << endl;*/
	}
	return 0;
}