#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isConsonant(char ch){
	return !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int ans(string & word, int n){
	std::vector<bool> prec(word.length());
	int cnt = 0;
	int total = 0;

	for(int i = 0; i < word.length(); ++i){
		if(isConsonant(word.at(i))){
			if(cnt < n)
				++cnt;
		} else {
			cnt = 0;
		}

		if(cnt >= n){
			prec[i] = true;
		} else {
			prec[i] = false;
		}
	}

	for(int i = 0; i < word.length(); ++i){
		for(int j = i; j < word.length(); ++j){
			for(int k = i+n-1; k <= j; ++k){
				if(prec[k]){
					++total;
					// cout << "\t (" << i << ',' << j << ',' << k << ')' << endl;
					break;
				}
			}
		}
	}

	// cout << endl << "\tprec= ";
	// for(int i = 0; i < word.length(); ++i){
	// 	cout << prec[i];
	// }
	// cout << endl;

	return total;
}

int main(){
	int cases;
	int name, n;
	string word;

	cin >> cases;

	for(int i = 1; i <= cases; ++i){
		cin >> word >> n;
		cout << "Case #" << i << ": " << ans(word, n) << endl;
	}


	return 0;
}