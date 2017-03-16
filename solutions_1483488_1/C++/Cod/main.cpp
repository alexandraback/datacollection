#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>

using namespace std;


string Cycle(string &a_str, int a_n)
{
	string l_res;
	int l_len = a_str.length();

	if (a_n >= l_len)
		return a_str;

	for (int i = l_len - a_n; i < l_len; ++i)
		l_res+=a_str[i];

	for (int i = 0; i < l_len - a_n; ++i)
		l_res+=a_str[i];

	return l_res;
}

void Cycle(string& a)
{
	int len = a.length();
	char last = a[len - 1];

	for (int i = len - 1; i > 0; --i)
		a[i] = a[i - 1];

	a[0] = last;	
}


inline bool ValidateNumbers(int A, int n, int m, int B)
{
	if ( A <= n && n < m && m <= B)
		return true;
	else
		return false;
}

void main()
{
	int l_testCases;
	cin>>l_testCases;

	for (int l_i = 0; l_i < l_testCases; ++l_i)
	{
		int l_count = 0;
		string aStr, bStr;
		cin>>aStr>>bStr;

		int aInt = atoi (aStr.c_str());
		int bInt = atoi (bStr.c_str());

		for (int n = aInt; n <= bInt; ++ n)
		{
			char buf[32];
			memset(buf, '\0', 32);
			_itoa(n, buf, 10);

			string l_start(buf);
			string l_current = l_start;
			Cycle(l_current);

			while (l_current != l_start)
			{
				int m = atoi(l_current.c_str());
				
				if (ValidateNumbers(aInt, n, m, bInt))
					++l_count;
				Cycle(l_current);
			}
		}
		cout<<"Case #"<<(l_i+1)<<": "<<l_count<<endl;
	}

}