#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

/*int getTotal(string _str)
{
	int res = 0;
	int temp = 0;
	for(int i = 0; i < _str.size(); ++i)
	{
		if( _str[i] != 'a' && _str[i] != 'e' && _str[i] != 'i' && _str[i] != 'o' &&  _str[i] != 'u')
		{
			++temp;
		}
		else
		{
			res = max(res, temp);
			temp = 0;
		}
	}

	res = max(res, temp);

	return res;
}*/

bool isCon(string _str)
{
	for(int i = 0; i < _str.size(); ++i)
	{
		if( _str[i] != 'a' && _str[i] != 'e' && _str[i] != 'i' && _str[i] != 'o' &&  _str[i] != 'u')
		{
		}
		else
		{
			return false;
		}
	}

	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);

	int N;
	cin >> N;

	for(int T = 0; T < N; ++T)
	{
		string str;
		int n;
		cin >> str >> n;

		unsigned long long res = 0;
		bool included = false;
		int prev = 0;
		for(int i = 0; i <= (int)str.size() - n; ++i)
		{
			string temp = str.substr(i, n);

			if(isCon(temp))
			{
				if( (i == (int)str.size() - n || i == 0) && !included)
				{
					included = true;
					res += i + 1 - prev;
					res += (int)str.size() - (i+n);
				}
				else if( (i == (int)str.size() - n || i == 0) && included )
				{
					res += i + 1 - prev;
					res += (int)str.size() - (i+n);
				}
				else
				{
					res += i + 1 - prev;
					res += (unsigned long long)str.size() - (i+n);
					if( prev < i )
						res += (unsigned long long)(i - prev) *  ((unsigned long long)str.size() - (i+n));
				}
				prev = i+1;
			}
		}

		/*int res = 0;
		for(int i = 0; i < (int)str.size(); ++i)
		{
			for(int j = 1; j <= (int)str.size() - i; ++j)
			{
				string temp = str.substr(i, j);
				int t = getTotal(temp);
				if( t >= n)
					++res;
			}
		}*/

		cout << "Case #" << (T+1) << ": " << res << endl;
	}

	return 0;
}