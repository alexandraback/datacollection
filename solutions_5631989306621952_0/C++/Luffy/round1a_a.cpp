#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

bool go_front(string cur, char ch) {
	string fr = cur;
	fr.insert(0, 1, ch);
	string ba = cur;
	ba.push_back(ch);
	return fr > ba;
}

int main(){
	freopen("output.txt","w",stdout);
	freopen("A-small-attempt1.in","r",stdin);
	int T;
	cin >> T;
	//cerr << T << " troll\n";
	string s;
	int n;
	for (int t=1; t<=T; t++) {
		cin >> s;
		//cerr << "troll\n";
		n = s.length();
		string ans;
		ans.push_back(s[0]);
		for (int i=1; i<n; i++) {
			if (go_front(ans, s[i])) {
				ans.insert(0, 1, s[i]);
			}else {
				ans.push_back(s[i]);
			}
		}
		cout << "Case #" << t << ": " << ans << "\n";
	}
	return 0;
}