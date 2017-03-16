#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isConsonant(char c)
{
	return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
	int t;
	cin>>t;
	string s;
	int n;
	for (int z = 0; z < t; ++z)
	{
		cin>>s>>n;
		vector<pair<int, int> > a;
		bool isPrevConsonant = false;
		int from = 0, len = -1;
		for (int i = 0; i < s.size(); ++i)
		{
			if (isConsonant(s[i]))
			{
				if (!isPrevConsonant)
					from = i, len = 0;
				isPrevConsonant = true;
				++len;
			}
			else 
			{
				if (isPrevConsonant && len >= n)
					a.push_back(make_pair(from, len));
				isPrevConsonant = false;
			}
		}
		if (isPrevConsonant && len >= n)
			a.push_back(make_pair(from, len));
		int next = 0;
		long long res = 0;
		if (a.size() != 0)
		{
			for (int i = 0; i < s.size(); ++i)
			{
				if (a[next].first + a[next].second - i < n)
				{
					++next;
					if (next == a.size())
						break;
				}
				int from = max(a[next].first, i) + n - 1;
				res += s.size() - from;
			}
		}
		cout<<"Case #"<<(z+1)<<": "<<res<<endl;
	}
	return 0;
}

