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
		string s;
		cin >> s;
		const int n = s.size();
		vector<int> max_letter(n);
		max_letter[0] = s[0];
		for(int i = 1; i < n; ++i){
			max_letter[i] = max<int>(max_letter[i - 1], s[i]);
		}
		vector<bool> used(n);
		vector<char> result;
		for(int i = n - 1; i >= 0; --i){
			if(s[i] == max_letter[i]){
				result.push_back(s[i]);
				used[i] = true;
			}
		}
		for(int i = 0; i < n; ++i){
			if(!used[i]){ result.push_back(s[i]); }
		}
		result.push_back('\0');
		cout << "Case #" << case_num << ": " << result.data() << endl;
	}
	return 0;
}

