#include <iostream>
#include <memory.h>
using namespace std;

const int nLetter = 26;
int main(){
	int cnt[nLetter];
	char check[12] = "ZOWHUFXSGI";
	string s;
	string digits[12] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	int passOne[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
	int nDigit[10];
	int t;
	cin >> t;
	for(int k = 0; k < t; k ++){
		cout << "Case #" << k + 1 << ": ";
		memset(cnt, 0, sizeof(cnt));

		cin >> s;
		int l = s.length();
		for(int i = 0; i < l; i ++){
//			cout << s[i] - 'A' << endl;
			cnt[s[i] - 'A'] ++;
		}
		/*
		for(int i = 0; i < nLetter; i ++){
			cout << cnt[i] << " ";
		}
		cout << endl;
		*/

		memset(nDigit, 0, sizeof(nDigit));
		for(int i = 0; i < 10; i ++){
			int d = passOne[i];
			int c = check[d] - 'A';
//			cout << d << "-" << cnt[c] << endl;
			nDigit[d] += cnt[c];
			for(int j = 0; j < digits[d].length(); j ++){
				int cp = digits[d][j] - 'A';
				if(c == cp)
					continue;
//				cout << cp << "--";
				cnt[cp] -= cnt[c];
			}
//			cout << endl;
			cnt[c] = 0;
		}
		for(int i = 0; i < 10; i ++){
			for(int j = 0; j < nDigit[i]; j ++)
				cout << i;
		}
		cout << endl;
	}
	return 0;
}

