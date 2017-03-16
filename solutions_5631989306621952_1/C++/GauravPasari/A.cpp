#include <iostream>
#include <string>
using namespace std;

string solution(string s)
{
	string result = "";
	result += s[0];
	for (int i=1; s[i]; ++i)
	{
		char c = s[i];
		if (c >= result[0])
		{
			result = s[i] + result;
		}
		else
		{
			result += c;
		}
	}
	return result;
}
int main()
{
	int t; cin >> t;
	string s;
	for (int i=1; i<=t; i++)
	{
		cin >> s;
		cout << "Case #" << i << ": " << solution(s) << endl;
	}
	return 0;
}