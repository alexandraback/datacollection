#include <iostream>
#include <string>

using namespace std;

bool isvowel(char c) {
	const char v[] = "aeiou";
	for (int i=0;i<sizeof(v); i++) {
		if (c==v[i]) return true;
	}
	return false;
}

int main() {

	int T;
	cin >> T;
	
	
	for (int t=0; t<T; t++) {
		string s;
		int n;
		cin >> s;
		cin >> n;

		int len = s.size();
		int cons = 0;
		int ans = 0;
		int p=-1;
		for (int i = 0; i < len ; i++) {
			if (isvowel(s[i])) {
				cons = 0;
			} else {
				cons++;
				if (cons >= n) {
					ans += (len - i) * (i-n-p+1);
					//cout << i << " ";
					//cout << (len - i)  << "*" <<  (i-n-p+1) << endl;
					p = i - n + 1;
				}
			}
		}
		
		cout << "Case #" << (t+1) << ": " << ans << endl;
	
	}

	return 0;
}


