#include <iostream>

#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;

	cin >> T;

	for(int tc = 1; tc <= T; ++tc)
	{
		int ans = 0;

		int r, c, w;

		cin >> r >> c >> w;

		ans += r * (c / w);

		ans += w - 1;

		if(c % w)
			++ans;


		cout << "Case #" << tc << ": " << ans << endl;
	}

	return 0;
}