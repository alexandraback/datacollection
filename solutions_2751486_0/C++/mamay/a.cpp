#include <iostream>
#include <string>

using namespace std;

int f(string& s, int n)
{
	int len = (int) s.size();
	int res = 0;
	for(int i = 0; i < len; ++i)
		for(int j = n; j <= len-i; ++j)
		{
			string a = s.substr(i, j);
			bool ok = true;
			int m = 0;
			int t = 0;
			for(int k = 0; k < j; ++k)
			{
				if(a[k] == 'a' or a[k] == 'e' or a[k] =='i' or a[k] =='o' or a[k] == 'u')
				{
					if(m < t) m = t;
					t = 0;
				}
				else
				{
					++t;
				}
			}
			if(m < t) m = t;
			
			if(m >= n) ++res;
		}
	return res;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i)
	{
		string s;
		cin >> s;
		int n;
		cin >> n;
		cout << "Case #" << i << ": " << f(s, n) << endl;
	}

	return 0;
}
