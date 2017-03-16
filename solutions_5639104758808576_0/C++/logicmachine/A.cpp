#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		int n;
		string s;
		cin >> n >> s;
		vector<int> a;
		for(int i = 0; i <= n; ++i){
			for(int j = '0'; j < s[i]; ++j){ a.push_back(i); }
		}
		const int m = a.size();
		int answer = 0;
		for(int i = 0; i < m; ++i){
			if(a[i] > i + answer){ answer = a[i] - i; }
		}
		cout << "Case #" << case_num << ": " << answer << endl;
	}
	return 0;
}

