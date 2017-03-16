#include <cstdio>
#include <iostream>

using namespace std;

int t;
string s;
int d;

int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> s;
		s = s + '+';
		d = 0;
		for (int j = 1; j < s.length(); j++)
		{
			if (s[j] != s[j - 1])
			{
				d++;
			}
		}
		cout << "Case #" << i << ": " << d << endl;
	}
	return 0;
}
