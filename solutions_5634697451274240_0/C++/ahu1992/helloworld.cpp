#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<numeric>
using namespace std;

class Solution{
public:
	int solve(string& s)
	{
		int x, y;
		if (s[0] == '+')
		{
			x = 1;
			y = 0;
		}
		else
		{
			x = 0;
			y = 1;
		}
		for (size_t i = 1; i < s.size(); ++i)
		{
			if (s[i] == '+')
				x = y + 1;
			else
				y = x + 1;
		}
		return y;
	}
};

int main()
{
	//ifstream in("A-large.in");
	//ofstream out("large_output.out");
	istream& in = cin;
	ostream& out = cout;
	Solution A;
	int T;
	in >> T;
	string s;
	for (int i = 1; i <= T; ++i)
	{
		in >> s;
		out << "Case #" << i << ": ";
		cout << A.solve(s) << endl;
	}
	return 0;
}