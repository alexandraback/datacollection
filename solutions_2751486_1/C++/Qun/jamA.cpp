#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

typedef long long int int64;


inline bool is_boin(char c)
{
	return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
}

inline bool is_siin(char c){
	return !is_boin(c);
}

//jamA
int main(void)
{
	int64 nTestCase, repeat;
	int64 i;
	string s;
	int64 N;

	int64 nSiinRepeat, nPrev, nTotal;

	cin >> nTestCase;
	for(repeat = 1; repeat <= nTestCase; repeat++){
		cin >> s >> N;

		nSiinRepeat = 0;
		nPrev = 0;
		nTotal = 0;

		// 最初の2文字をスキャン
		/*
		for(i = 0; i < 2 && i < s.length(); i++){
			if(is_siin(s[i])){
				nSiinRepeat++;
			}else{
				nSiinRepeat = 0;
			}
		}
		*/

		// 3文字目からが本番
		for(i = 0; i < s.length(); i++){
			if(is_siin(s[i])){
				nSiinRepeat++;
				if(nSiinRepeat >= N){
					nPrev = i - N + 2;
					nTotal += nPrev;
				}else{
					nTotal += nPrev;
				}
			}else{
				nTotal += nPrev;
				nSiinRepeat = 0;
			}
		}

		// 結果出力
		cout << "Case #" << repeat << ": " << nTotal << endl;
		cerr << "Case #" << repeat << ": " << nTotal << endl;
	}

	return 0;
}

