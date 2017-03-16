#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	ifstream cin ( "input.txt" );
	ofstream cout ( "output.txt" );
	int t;
	cin >> t;
	for (int t1 = 0; t1 < t; ++t1)
	{
		cout << "Case #" << t1 + 1 << ": ";
		int x, y;
		cin >> x >> y;
		bool flag1 = false, flag2 = false; 
		if (x < 0)
		{
			x *= -1;
			flag1 = true;
		}
		if (y < 0)
		{
			y *= -1;
			flag2 = true;
		}
		while (x > 0)
		{
			if (flag1)
				cout << "EW";
			else
				cout << "WE";
			--x;
		}
		while (y > 0)
		{
			if (flag2)
				cout << "NS";
			else
				cout << "SN";
			--y;
		}
		cout << endl;
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