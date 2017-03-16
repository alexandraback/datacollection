
#include <iostream>

using namespace std;

int A, B;

int bs[10];

inline int rec_count(int a)
{
	if (a <= 9) return 0;

	int aa = a;
	int dig = 1, big = 1;
	while ((aa /= 10) > 0)
	{
		dig++;
		big *= 10;
	}

	int res = 0;
	int b = a, c = 0;
	for (int i = 1; i < dig; i++)
	{
		b = big * (b % 10) + b / 10;
		//cout << a << " -> " << b << endl;
		
		if (a >= b || b < A || b > B) continue;

		bs[c] = b;
		bool seen = false;
		for (int k = 0; k < c; k++) if (bs[k] == b) { seen = true; break; }
		if (seen) continue;
		c++;

		res++;
	}

	return res;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";

		cin >> A >> B;

		int count = 0;

		for (int j = A; j <= B; j++)
		{
			count += rec_count(j);
		}

		cout << count << endl;
	}

	return 0;
}
