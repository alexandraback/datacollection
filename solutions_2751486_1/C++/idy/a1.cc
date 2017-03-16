#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool is_con(char x) {
	return !(x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
}
void solve() {
	long long cnt = 0;
	int n;
	string name;
	pair<int, int> window, pwindow;
	cin >> name >> n;
	pwindow.first = -1;
	window.first = 0;
	window.second = -1;
	for(size_t i=0; i<name.size(); ++i) {
		if(is_con(name[i])) {
			if(window.second == -1)
				window.first = i;
			window.second = i;
		}
		else {
			window.second = -1;
		}

		if(window.second-window.first+1 > n) {
			
			window.first = window.second - n + 1;
		}

		if(window.second - window.first + 1 == n) {
			//cout << window.first << " " << window.second << ": " << (window.first - pwindow.first) * 1ll * (name.size() - window.second) << endl;
			cnt += (window.first - pwindow.first) * 1ll * (name.size() - window.second);
			pwindow = window;
		}
	}
	cout << cnt;
}
int main() {
	int casn;
	cin >> casn;
	for(int casi=1; casi <= casn; ++casi) {
		cout << "Case #" << casi << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
