#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


string s;

bool palindrome(long long x)
{
	s = "";
	while (x > 0)
	{
		s += '0' + x % 10;
		x /= 10;
	}

	bool ok = true;
	for (int i = 0; i < s.length() / 2; i++)
		ok &= (s[i] == s[s.length() - 1 - i]);
	return ok;
}

vector <long long> fs, qs;
const long long MAXA = 10000001;

void precalc()
{
	for (long long x = 1; x <= MAXA; x++)
		if (palindrome(x) && palindrome(x * x))
		{
			fs.push_back(x * x);
			qs.push_back(x);
		}
}

int main()
{
	ifstream cin ("input.txt");
	ofstream cout("output.txt");

	precalc();
	
	int T;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		long long A, B, ans = 0;
		cin >> A >> B;
		
		for (int i = 0; i < fs.size(); i++)
			if (A <= fs[i] && fs[i] <= B)
				ans++;
		
		cout << "Case #" << test + 1 << ": ";
		cout << ans;
		cout << endl;
	}
	return 0;
}