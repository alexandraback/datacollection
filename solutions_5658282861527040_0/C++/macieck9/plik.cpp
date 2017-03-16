#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int a,b,k;
		cin >> a >> b >> k;
		long long ans = 0;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				if ((i&j) < k) ans++;
			}
		}
		cout << "Case #" << t << ": ";
		cout << ans << "\n";
	}




    return 0;
}
