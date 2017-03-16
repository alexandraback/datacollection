#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("D:\\A-small-attempt0 (1).in", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);

	int t, r, c, w, ans;

	cin >> t;
	for (int tt = 1; tt <= t; tt++){
		cin >> r >> c >> w;
		// r == 1
		ans = 0;
		if (c%w == 0){
			ans = c / w - 1 + w;
		}
		else{
			ans = c / w + w;
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
	//system("pause");
	return 0;
}