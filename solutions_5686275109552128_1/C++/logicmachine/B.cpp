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
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){ cin >> a[i]; }
		sort(a.begin(), a.end());
		int answer = a.back();
		for(int i = 1; i <= a.back(); ++i){
			int step = 0;
			for(int j = 0; j < n; ++j){ step += (a[j] - 1) / i; }
			answer = min(answer, step + i);
		}
		cout << "Case #" << case_num << ": " << answer << endl;
	}
	return 0;
}

