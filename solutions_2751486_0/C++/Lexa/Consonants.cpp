//============================================================================
// Name        : Consonants.cpp
// Author      : J.Son
// Version     :
// Copyright   : GNU LGPL
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

bool isVowel(char s) {
	return (s == 'a' || s == 'e' || s == 'i' || s =='o' || s == 'u');
}

int main() {
	int cases;
	cin >> cases;
	for(int cas = 1; cas <= cases; cas++) {
		string s;
		int n, l;

		long long nValue = 0;
		cin >> s >> n;
		l = s.length();
		for(int i = 0; i < l - n + 1; i++) {
			for(int j = i + n - 1; j < l; j++) {
				int cnt = 0;
				for(int k = i; k <= j; k++) {
					if(isVowel(s[k])) {
						cnt = 0;
					} else {
						cnt++;
					}
					if(cnt >= n) {
						nValue++;
						break;
					}
				}
			}
		}
		cout << "Case #" << cas << ": " << nValue << endl;
	}
	return 0;
}
