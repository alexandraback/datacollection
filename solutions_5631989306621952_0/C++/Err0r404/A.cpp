#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream cin("AS.in");
	ofstream cout("AS.txt");
	int T; cin >> T;
	for (int i=0;i<T;i++){
		string s; cin >> s;
		string ans = "";
		ans = ans + s[0];
		for (int i=1;i<s.length();i++){
			if (ans[0] <= s[i]) ans = s[i] + ans;
			else ans = ans + s[i];
		}
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
