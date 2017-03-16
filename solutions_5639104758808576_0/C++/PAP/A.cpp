#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++)
	{
		int n, ans = 0, sum = 0;
		string s;
		cin >> n;
		cin >> s;
		for(int i = 0; i <= n; i++)
			if(sum < i)
			{
				ans += i - sum;
				sum += i - sum + s[i] - '0';
			}
			else
				sum += s[i] - '0';
		cout << "Case #" << tt << ": ";
		cout << ans << endl;
	}
	return 0;
}
