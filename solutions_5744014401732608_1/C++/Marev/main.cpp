#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

stringstream out;

int tab[10000];

void function()
{
	long long b, m;
	cin >> b >> m;
	if (m > pow(2, b - 2)) {
		out << "IMPOSSIBLE\n";
		return;
	}
	out << "POSSIBLE\n";
	if (m == pow(2, b - 2)) {
		out << "0" << string(b - 1, '1') << endl;
	}
	else
	{
		int a = 0;
		string result = "";
		while (m != 0) {
			tab[a] = m % 2;
			m = m / 2;
			result = (char)(tab[a] + '0') + result;
			a++;
		}
		result = string(b - a - 2, '0').append(result);
		out << "0" << result << "0";
		out << endl;
	}
	for (int i = 1; i < b; i++)
	{
		for (int j = 0; j < i + 1; j++)
			out << "0";
		for (int j = i + 1; j < b; j++)
			out << "1";
		out << endl;
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		out << "Case #" << i << ": ";
		function();
	}
	
	cout << out.str() << endl;
	return 0;
}