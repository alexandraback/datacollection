#define CRT_NO_SECURE_WARNINGS
#include <string>
#include <fstream>
using namespace std;
long long gcd(long long a, long long b)
{
	while (a != 0 && b != 0)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}
int main()
{
	ifstream cin("A-small-attempt1.in");
	ofstream cout("output.txt");
	int t;
	cin >> t;
	for (int q = 1; q <= t; ++q)
	{
		cout << "Case #" << q << ": ";
		char a[1024];
		cin.getline(a, 1024, '/');
		long long u = atoi(a);
		cin.getline(a, 1024, '\n');
		long long l = atoi(a);

		long long g = gcd(u, l);
		u /= g; l /= g;
		int i = 0, answ = 0;
		while (true)
		{
			++i;
			if (l % 2 == 0)
			{
				l /= 2;
			}
			else break;
			if (u >= l)
			{
				u -= l;
				if (!answ)
					answ = i;
			}
		}
		if (answ && u == 0)
			cout << answ;
		else cout << "impossible";
		cout << endl;
	}
}