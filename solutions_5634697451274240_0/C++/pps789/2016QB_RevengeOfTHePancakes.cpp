#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		string str; cin >> str;
		str.erase(unique(str.begin(), str.end()), str.end());

		if ((*str.rbegin()) == '-'){
			cout << str.size() << endl;
		}
		else cout << str.size() - 1 << endl;
	}
}