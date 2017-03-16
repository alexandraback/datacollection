#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t, tt = 1;
	for(cin >> t; t; t--, tt++){
		cout << "Case #" << tt << ": ";
		long long int k, c, s;
		cin >> k >> c >> s;
		if(c == 1 && k == 1){
			cout << 1 << endl;
			continue;
		}
		if((c == 1 && s < k) || (c > 1 && s < k - 1)){
			cout << "IMPOSSIBLE\n";
			continue;
		}
		if(s == k){
			for(int i = 0; i < s; i++)
				cout << i + 1 << " ";
			cout << endl;
			continue;
		}
		long long int step = 1, pos = 1;
		for(int i = 0; i < c - 1; i++, step *= k){}
		for(int i = 0; i < min(s, k-1); i++){
			pos += 1;
			cout << pos << " ";
			pos += step;
		}
		cout << endl;
	}

	return 0;
}