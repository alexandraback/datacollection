#include <iostream>

using namespace std;

string solve(string& str)
{
	string last;
	for (unsigned i = 0; i < str.size(); ++i)
	{
		if (last.empty())
			last += str[i];
		else if (str[i] >= last[0])
		{
			string newstr;
			newstr += str[i];
			newstr += last;
			last = newstr;
		}
		else
			last += str[i];
	}

	return last;
}

int main()
{
	unsigned numInputs = 0;

	cin >> numInputs;

	for (size_t i=0; i< numInputs; ++i)
	{
		string str;

		cin >> str;

		cout << "Case #" << i + 1 << ": " << solve(str) << endl;
	}
	return 0;
}

