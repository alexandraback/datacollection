#include<iostream>

using namespace std;

int T[105];

int main()
{
	ios_base::sync_with_stdio(0);
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++)
	{
		string S;
		cin >> S;
		S += "+";
		int ans = 0;
		for (int i = 1; i < S.size(); i++)
		{
			if (S[i] != S[i - 1]) ans++;
		}
		cout << "Case #" << t << ": " << ans << "\n";
	}
	
	
	return 0;
}
