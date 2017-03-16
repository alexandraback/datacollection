#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	freopen("small.in", "r", stdin);
	freopen("small.out", "w", stdout);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		deque<char> ans, L, R;

		string str; cin >> str;
		for (int i = 0; i < str.size(); i++){
			L.push_front(str[i]);
			R.push_back(str[i]);
			ans = max(L, R);
			L = ans, R = ans;
		}

		while (!ans.empty()){
			cout << ans.front();
			ans.pop_front();
		}
		cout << endl;
	}
}