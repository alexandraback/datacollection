#include <iostream>
using namespace std;

int main()
{
	int t, n, s, p, i, dc, count, w;

	//freopen("dancer.in", "r", stdin);
	//freopen("dancer.out", "w", stdout);
	cin >> t;
	for(w = 0; w < t; w++) {
		cin >> n >> s >> p;
		cout << "Case #" << w + 1 << ": ";
		count = 0;
		for(i = 0; i < n; i++) {
			cin >> dc;
			if(p > dc) continue;
			if(p == dc && dc == 1) {
				count++;
				continue;
			}
			if(p == dc && dc == 2 && s > 0) {
				count++;
				s--;
				continue;
			}
			int k = (dc - p) / 2;
			if(p - k <= 1) count ++;
			else if(s > 0 && p - k <= 2) s--, count++;
		}
		cout << count << endl;
	}
	//system("pause");
	return 0;
}