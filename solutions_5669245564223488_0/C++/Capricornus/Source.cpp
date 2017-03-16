#include <vector>
#include <string>
#include <fstream>
#include <set>
using namespace std;
struct car
{
	char start, end;
	friend bool operator <(const car &a, const car &b)
	{
		return (a.start < b.start || (a.start == b.start && a.end < b.end));
	}
};
int main()
{
	ifstream cin("B-small-attempt2.in");
	ofstream cout("output.txt");

	int t;
	cin >> t;
	for (int q = 1; q <= t; ++q)
	{
		cout << "Case #" << q << ": ";
		int n;
		cin >> n;

		set<car> a;
		string s;
		set<char> StEnA;
		set<char> MidA;

		bool hassolution = true;
		long long mult = 1;

		for (int i = 0; i < n; ++i)
		{
			cin >> s;

			int countm = 0;
			for (int j = 1; j < s.length() - 1; ++j)
			{
				if (s[j] != s[j - 1] && s[j] != s[j + 1])
				{
					if (MidA.find(s[j]) == MidA.end())
						MidA.insert(s[j]);
					else mult = 0;
				}
			}
			car c;
			c.start = s[0];
			c.end = s[s.length() - 1];
			int ll = s.length() - 2;
			if (c.start == c.end && ll > 0)
				mult = 0;
			if (a.find(c) != a.end())
				mult *= 2;
			else
			{
				a.insert(c);
			}

			StEnA.insert(s[0]);
			StEnA.insert(s[s.length() - 1]);
		}

		for (set<char>::iterator i = MidA.begin(); i != MidA.end(); ++i)
		{
			if (StEnA.find(*i) != StEnA.end())
			{
				hassolution = false;
				break;
			}
		}
		long long countsets = 0;
		long long result = mult;
		if (!hassolution)
		{
			cout << "0";
		}
		else
		{
			while (!a.empty())
			{
				countsets++;
				vector<char> train;
				train.reserve(100 * n);

				train.push_back((*a.begin()).start);
				train.push_back((*a.begin()).end);

				a.erase(a.begin());
				if (train[0] == train[train.size() - 1] && train.size()>2)
					result = 0;
				for (set<car>::iterator i = a.begin(); i != a.end() ;)
				{
					if ((*i).start == train[train.size() - 1])
					{
						train.push_back((*a.begin()).start);
						train.push_back((*a.begin()).end);
						a.erase(i);
						if (train[0] == train[train.size() - 1])
							result = 0;
						if (a.empty())
							break;
						i = a.begin();
						
					}
					else if ((*i).end == train[0])
					{
						train.insert(train.begin(), (*i).end);
						train.insert(train.begin(), (*i).start);
						a.erase(i);
						if (train[0] == train[train.size() - 1])
							result = 0;
						if (a.empty())
							break;
						i = a.begin();
					}
					else ++i;
				}
			}
			for (int i = 2; i <= countsets; ++i)
				result = (result * i) % 1000000007;
			cout << result;
		}

		
		cout << endl;
	}
}