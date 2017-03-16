#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	scanf("\n");
	vector<string> words(T);
	for (int i = 0; i < T; i++)
	{
		string buf;
		getline(cin, buf);
		string ans = "A";
		ans[0] = buf[0];
		for (int j = 1; j < buf.size(); j++)
		{
			if (ans[0] > buf[j])
				ans = ans + buf[j];
			else
				ans = buf[j] + ans;
		}
		printf("Case #%d: ", i + 1);
		cout << ans << "\n";
	}
	return 0;
}