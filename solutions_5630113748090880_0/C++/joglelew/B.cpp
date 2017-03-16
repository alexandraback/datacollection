#include <iostream>
#include <cstring>
#define MAXHEIGHT 2502
using namespace std;

int count[MAXHEIGHT];

int main()
{
	int t, n, i, j, h;
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	cin >> t;
	for (int times = 1; times <= t; times++) {
		cin >> n;
		memset(count, 0, sizeof(count));
		for (i = 1; i <= n; i++)
			for (j = 1; j <= 2 * n - 1; j++) {
				cin >> h;
				count[h]++;
			}
		cout << "Case #" << times << ":";
		for (i = 1; i <= 2500; i++)
			if (count[i] % 2 == 1)
				cout << " " << i;
		cout << endl; 
	}
	return 0;
}
