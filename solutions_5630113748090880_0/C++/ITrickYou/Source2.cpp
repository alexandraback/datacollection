#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int count = 0;
	while (n--)
	{
		int height[2505] = { 0 };
		count++;
		int r;
		cin >> r;
		for (int i = 0; i < (2 * r -1) *r; i++)
		{
			int t;
			cin >> t;
			height[t]++;
		}
		cout << "Case #" << count << ": ";
		int found = 0;
		int ind = 0;
		while (found != r)
		{
			if (height[ind] % 2 == 1)
			{
				cout << ind;
				found++;
				if (found != r)
					cout << " ";
			}
			ind++;
		}
		cout << endl;
	}
	return 0;
}