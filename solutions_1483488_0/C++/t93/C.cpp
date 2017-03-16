#include <iostream>

using namespace std;

int l;
int place;
int seen[2000001];

int rotate(int x)
{
	return (x / 10) + place * (x % 10);
}

int main()
{
	int t;
	cin >> t;

	for (int c = 0; c < t; c++)
	{
		for (int i = 0; i < 2000001; i++) seen[i] = 0;
		int a, b;
		cin >> a >> b;

		int temp = a;
		l = 0;
		place = 1;
		while (temp > 0)
		{
			l++;
			place *= 10;
			temp /= 10;
		}
		place /= 10;

		int count = 0;

		for (int i = a; i <= b; i++)
		{
			int x = i;
			for (int j = 1; j < l; j++)
			{
				x = rotate(x);
				if (x >= a && x < i && seen[x] != i) { count++; seen[x] = i; }
			}
		}

		cout << "Case #" << c+1 << ": " << count << "\n";
	}
}
