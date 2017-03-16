#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
		int n;
		cin >> n;
		string S;
		cin >> S;
		int cnt = 0;
		int ans = 0;
		for (int i = 0; i <= n; i++)
		{
			ans = max(ans,i-cnt);
			int x = S[i]-'0';
			cnt += x;
		}
		cout << "Case #" << t << ": " << ans << "\n";
	}


    return 0;
}
