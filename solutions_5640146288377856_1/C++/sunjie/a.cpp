#include <bits/stdc++.h>

using namespace std;


int main()
{
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	int cas = 0;
	while (T--)
	{
		printf("Case #%d: ", ++cas);
		int R, C, W;
		cin >> R >> C >> W;
		if (C % W)
		{
			cout << C / W * R + W << endl;
		}
		else
		{
			cout << C / W * R + W - 1 << endl;
		}
	}

	 fclose(stdin);
	 fclose(stdout);
	return 0;
}