#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	unsigned long long result = 1;
	if (b == 0)
	{
		result = a;
	}
	else if (a < b)
	{
		result = gcd(b, a);
	}
	else if (a % 2 == 0 && b % 2 == 0)
	{
		result = 2 * gcd(a / 2, b / 2);
	}
	else
	{
		result = gcd(a  % b, b);
	}
	return result;
}

void solve(int index)
{
	cout << "Case #" << index + 1 << ": ";
	string s;
	cin >> s;
	unsigned long long a = 0;
	int i = 0;
	for (; i < s.size() && s[i] != '/'; ++i)
	{
		a = a * 10 + (s[i] - '0');
	}
	++i;
	unsigned long long b = 0;
	for (; i < s.size() && s[i] != '/'; ++i)
	{
		b = b * 10 + (s[i] - '0');
	}
	unsigned long long g = gcd(a, b);
	a = a / g;
	b = b / g;
	int answer = 0;
	/*while (a < b)
	{
		++answer;
		a = a * 2;
	}*/
	while (a < b)
	{
		++answer;
		a *= 2;
	}
	unsigned long long test = 1;
	for (i = 0; i < 40; ++i)
	{
		test *= 2;
	}
	bool tst = true;
	unsigned long long b2 = b;
	while (b2)
	{
		tst = tst && (b2 > 0 && ((b2 == 1) || (b2 % 2 == 0)));
		b2 /= 2;
	}
	//cout << test % b << " " << test / b << " " << answer << " ";
	if (((test % b) == 0) && tst)
	{
		cout << answer;
	}
	else
	{
		cout << "impossible";
	}
	cout << endl;
}

int main(int argc, char **argv)
{
	if (argc == 2 && string(argv[1]) == "-d")
	{
		cout << "Sleep for 10 seconds" << endl;
		Sleep(10 * 1000);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		solve(i);
	}
	return 0;
} 