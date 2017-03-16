#include <iostream>
#include <string>

using namespace std;

int main(void) {
	
	int tc;
	cin >> tc;
	
	for(int t = 1; t <= tc; t++) {
		string str;
		cin >> str;
		string ans = "";
		for (char ch : str) ans = max(ans + ch, ch + ans);
		cout << "Case #" << t << ": " << ans << endl;
	}
	
	return 0;
}
