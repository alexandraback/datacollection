#include <iostream>

#define INPUT "A-large.in"
#define OUTPUT "output.txt"

using namespace std;


///
void solve()
{
	int R, C, W;

	cin >> R >> C >> W;

	int ans = 0;

	ans += R*C/W;


	cout  << (C % W ? ans + W : ans -1 + W);
}

int main()
{
	int T, cases = 0;

	freopen("C:\\Users\\Frog\\Downloads\\"INPUT, "r", stdin);
	freopen("C:\\Users\\Frog\\Downloads\\"OUTPUT, "w", stdout);

	cin >> T;

	while (T--) {
		cout << "Case #" << ++cases << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

