#include <iostream>
#include <string>

using namespace std;

int main()
{
	freopen("123.in", "r", stdin);
	freopen("123.out", "w", stdout);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		string st;
		cin >> st;
		cout << "Case #" << i << ": ";
		string ans;
		for (int j = 0; j < st.size(); j++)
		{
			//if (j != 0) cout << "ans = " << ans << endl;
			if (j == 0 || st[j] >= ans[0])
			{
				ans = st[j] + ans;
			}
			else
			{
				ans = ans + st[j];
			}
		}
		cout << ans << endl;
	}
}