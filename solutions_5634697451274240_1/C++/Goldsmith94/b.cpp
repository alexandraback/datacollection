#include <iostream>
#include <string>

using namespace std;

#define ll long long int
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	int Case = 1;
	while (T--){
		string str;
		cin >> str;
		int n = str.size();
		int ret = 0;
		for (int i = 1; i < n; i++){
			if (str[i] != str[i-1]){
				ret += 1;
			}
		}
		if (str[n-1] == '-') ret++;
		cout << "Case #" << Case << ": " << ret << endl;
		Case++;
	}

}
