#include <iostream>
#include <string>

using namespace std;
int main() {
	freopen("C.out", "w", stdout);

	cout << "Case #1:\n";

	for (int i = 0; i < 50; ++i) {
		string ans = "11";

		for (int k = 0; k < 6; ++k) {
			if ((i >> k) & 1)
				ans = ans + "11";
			else
				ans = ans + "00";
		}

		ans = ans + "11";

		cout << ans << " 3 2 5 2 7 2 3 2 11 \n";
	}

	

}