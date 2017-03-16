#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

bool match(string str1, string str2) {
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] != '?' && str2[i] != '?' && str1[i] != str2[i]) {
			return false;
		}
	}
	return true;
}

string conv(int num, int len) {
	char str[len+1];
	for (int i = 0; i < len; i++) str[i] = '0'; str[len] = 0;
	int i = len-1;
	while (num > 0) {
		str[i] = '0' + (num%10);
		num /= 10;
		i--;
	}
	return string(str);
}

void bruteforce(string str1, string str2) {
	vector<int> n1, n2;
	int maxnum=1;
	for (int i = 0; i < str1.length(); i++) {
		maxnum *= 10;
	}
	for (int i = 0; i < maxnum; i++) {
		string x = conv(i, str1.length());
		if (match(x, str1)) {
			n1.push_back(i);
		}
		if (match(x, str2)) {
			n2.push_back(i);
		}
	}
	int mindiff = 10000000;
	int mina, minb;
	for (int i = 0; i < n1.size(); i++) {
		for (int j = 0; j < n2.size(); j++) {
			int diff = abs(n1[i] - n2[j]);
			if (diff < mindiff || diff == mindiff && 
					(n1[i] < mina || (n1[i] == mina && n2[j] < minb))) {
				mindiff = diff;
				mina = n1[i];
				minb = n2[j];
			}
		}
	}
	cout << conv(mina, str1.length()) << " " << conv(minb, str2.length()) << endl;
}

int main() {
	int nc; cin >> nc;
	for (int cs = 1; cs <= nc; cs++) {
		string s1, s2; cin >> s1 >> s2;
		string ans1 = s1;
		string ans2 = s2;

		cout << "Case #" << cs << ": ";
		bruteforce(s1, s2);
	}
}
