#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int tst, t , i , j , k , n,  m;
string a[4];

char check(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'T')
			if (i > 0)
				s[i] = s[i-1];
			else
				s[i] = s[i+1];

		if (s[i] == '.')
			s[i] = 0;
			
	}

	for (int i = 1; i < s.size(); i++)
		if (s[i] != s[i-1])
			return 0;

	return s[0];
}

int main()
{
	freopen("A-small-attempt0.in" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	cin>>tst;
	for (int t = 1; t <= tst; t++)
	{
		cout<<"Case #"<<t<<": ";
		for (i = 0; i < 4; i++)
			cin>>a[i];

		int filled = 1;
		int ansfound = 0;

		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				if (a[i][j] == '.')
					filled = 0;
				
		for (i = 0;  i < 4; i++)
		{
			char c = check(a[i]);
			if (c != 0)
			{
				cout<<c<<" won\n";
				ansfound = 1;
				break;
			}

			string s = "";
			for (j = 0; j < 4; j++)
				s += a[j][i];

			c = check(s);
			if (c != 0)
			{
				cout<<c<<" won\n";
				ansfound = 1;
				break;
			}

		}


		if (!ansfound)
		{
			string s1 = "" , s2 = "";
			for (i = 0; i < 4; i++)
			{
				s1 += a[i][i];
				s2 += a[i][3 - i];
			}

			char c = check(s1);
			if (c != 0)
			{
				cout<<c<<" won\n";
				ansfound = 1;
			}

			c = check(s2);
			if (c != 0)
			{
				cout<<c<<" won\n";
				ansfound = 1;
			}
		}

		if (!ansfound && filled)
			cout<<"Draw\n";
		else
			if (!ansfound)
			cout<<"Game has not completed\n";
	}
	return 0;
}