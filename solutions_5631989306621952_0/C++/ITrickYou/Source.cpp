#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int count = 0;
	while (n--)
	{
		count++;
		string s;
		cin >> s;
		string r;
		char maxi = 0;
		for (int i = 0; i < s.size(); i++)
		{
			char t = s[i];
			if (t >= maxi)
			{
				r = t + r;
				maxi = t;
			}
			else
			{
				r += t;
			}
		}
		cout << "Case #" << count << ": " << r << endl;
	}

	return 0;
}