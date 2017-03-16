#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	for (int i = 1; i <= te; i++){
		cout << "Case #" << i << ": ";
		string s, ans;

		cin >> s;
		for (char ch:s)
			ans = max(ans + ch, ch + ans);
		cout << ans << "\n";
	}
	return 0;
}
