//Problem A. Standing Ovation

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int t, kase = 0;
	cin >> t;
	while (t--)
	{
		int s_max;
		string str;
		cin >> s_max >> str;
		int sum = 0, ans = 0;
		for (int i = 0; i <= s_max; i++)
		{
			if (i > sum)
			{
				int tmp = i - sum;
				ans += tmp;
				sum += tmp;
			}
			sum += str[i] - '0';
		}
		cout << "Case #" << ++kase << ": " << ans << endl;
	}
	return 0;
}