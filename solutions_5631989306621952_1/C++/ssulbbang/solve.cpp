#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char** argv) {

	int n;

	cin >> n;

	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;

		string ret = "";
		for(int i = 0; i < s.size(); i++) {
			if(ret == "") {
				ret += s[i];
			} else if(ret[0] <= s[i]) {
				ret = s[i] + ret;
			} else {
				ret = ret + s[i];
			}
		}

		cout << "Case #" << i << ": " << ret << endl;
	
	}

	return 0;
}
