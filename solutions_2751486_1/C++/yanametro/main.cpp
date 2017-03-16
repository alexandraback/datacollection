#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isConsonant(char ch){
	return !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int ans(string & word, int n){
	std::vector<bool> prec(word.length());
	std::vector<long long int> rho(word.length());
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

	cnt = -1;

	for(int i = word.length()-n; i >= 0; --i){
		if(cnt != -1){
			++cnt;
		}
		if(prec[i+n-1]){
			cnt = n-1;
		}
		rho[i] = cnt;
	}

	//
	// for(int i = 0; i < word.length(); )

	for(int i = 0; i <= word.length()-n; ++i){
		if(rho[i] != -1){
			int lo = i+rho[i];
			int hi = word.length()-1;
			total += hi-lo+1;
		}
	}

	// for(int i = 0; i < word.length(); ++i){
	// 	for(int j = i; j < word.length(); ++j){
	// 		for(int k = i+n-1; k <= j; ++k){
	// 			if(prec[k]){
	// 				++total;
	// 				break;
	// 			}
	// 		}
	// 	}
	// }

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