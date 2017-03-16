#include <bits/stdc++.h>
using namespace std;

#define pow _pow

vector <int> res;
long long pow[11], num[11];
string a;

int main(){
	cout << "Case #1:\n";
	int cnt = 0;
	for (long long  i = (1ll << 15); i < (1ll << 16) && cnt < 50; ++i){
		if (!(i & 1)){
			continue;
		}
		for (int j = 2; j < 11; ++j){
			pow[j] = 1;
			num[j] = 0;
		}
		for (int k = 0; k < 16; ++k){
			for (int j = 2; j < 11; ++j){
				if (i & (1ll << k)){
					num[j] += pow[j];
				}
				pow[j] *= j;
			}
		}
		res.clear();
		for (int k = 2; k < 11; ++k){
			for (long long j = 2; j * j <= pow[k]; ++j){
				if (!(num[k] % j)){
					res.push_back(j);
					break;
				}
			}
		}
		if (res.size() == 9){
			cnt++;
			long long  l = i;
			a.clear(); 
			while (l){
				a += char('0' + (l & 1));
				l >>= 1;
			}
			reverse(a.begin(), a.end());
			cout << a;
			for (int k = 0; k < res.size(); ++k){
				cout << " " << res[k];
			}
			cout << "\n";
		}
	}
	return 0;
}
