#include <cstdio>
#include <iostream>
using namespace std;

unsigned long long int r, t, radius, p, c;

int main()
{
	//freopen("C:\\Users\\wayne\\Downloads\\input.txt", "r", stdin);
	//freopen("C:\\Users\\wayne\\Downloads\\output.txt", "w", stdout);
	freopen("C:\\Users\\wayne\\Downloads\\A-small-attempt0.in", "r", stdin);
	freopen("C:\\Users\\wayne\\Downloads\\Small-output.out", "w", stdout);
	//freopen("C:\\Users\\wayne\\Downloads\\A-large-practice.in", "r", stdin);
	//freopen("C:\\Users\\wayne\\Downloads\\Large-output.out", "w", stdout);
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> r >> t;
		radius = r + 1;
		c = 0;
		while (1)
		{
			p = radius * radius - (radius - 1) * (radius - 1);
			if (t >= p)
				c++;
			else
				break;
			radius += 2;
			t -= p;
		}
		cout << "Case #" << i << ": " << c << endl;
	}
	return 0;
}