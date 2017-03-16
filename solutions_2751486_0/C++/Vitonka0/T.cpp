#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check (char c)
{
	if (c == 'a' || c == 'o' || c == 'e' || c == 'u' || c == 'i')
		return true;
	return false;
}

int main ()
{
	ifstream cin ( "input.txt" );
	ofstream cout ( "output.txt" );
	int t;
	cin >> t;
	for (int t1 = 0; t1 < t; ++t1)
	{
		string s;
		cin >> s;
		int n;
		cin >> n;
		cout << "Case #" << t1 + 1 << ": ";
		int l = 0, r = 0;
		long long ans = 0;
		int cur = 0;
		while (r != s.size ())
		{
			if (!check (s [r]))
				++cur;
			else
				cur = 0;
			while (cur >= n && l <= r)
			{
				ans += (s.size () - r);
				if (r - l + 1 == n && !check (s[l]))
					--cur;
				++l;
			}
			++r;
		}
		cout << ans << endl;
	}
}


/*int main ()
{
	ifstream cin ( "input.txt" );
	ofstream cout ( "output.txt" );
	int t;
	cin >> t;
	for (int t1 = 0; t1 < t; ++t1)
	{
		string s;
		cin >> s;
		int n;
		cin >> n;
		cout << "Case #" << t1 + 1 << ": ";
		int ans = 0;
		for (int i = 0; i < s.size (); ++i)
			for (int j = i; j <s.size (); ++j)
			{
				int cur = 0;
				bool flag = false;
				for (int k = i; k <= j; ++k)
				{
					if (!check (s [k]))
						++cur;
					else
						cur = 0;
					if (cur >= n)
						flag = true;
				}
				ans += flag;
			}
		cout << ans << endl;
	}
}*/