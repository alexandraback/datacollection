#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int n;
		string s;
		cin >> n >> s;
		int sum = 0;
		int add = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (sum < i)
			{
				add += i - sum;
				sum = i;
			}
			sum += s[i] - '0';
		}
		cout << "Case #" << tt << ": " << add << endl;
	}
}
