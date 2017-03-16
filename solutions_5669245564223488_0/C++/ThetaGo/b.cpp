#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

unsigned long factorial_mod(int n) {
	unsigned long ret = 1;
	for(int i = 2; i <= n; i++) {
		ret *= i;
		ret = ret % 1000000007;
	}
	return ret;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		string temp;
		string simple_s[100];
		for(int j = 0; j < n; ++j) {
			cin >> temp;
			int t_size = temp.size();
			char diff_chars[100];
			diff_chars[0] = temp[0];
			int diff_cur_pos = 0;
			for(int k = 1; k < t_size; ++k) {
				if(temp[k] != diff_chars[diff_cur_pos]) {
					diff_cur_pos++;
					diff_chars[diff_cur_pos] = temp[k];
				}
			}
			diff_chars[diff_cur_pos+1] = '\0';
			// cout << diff_chars << endl;
			simple_s[j] = string(diff_chars);
		}
	 	sort(simple_s, simple_s+n);
	 	string cur_string = simple_s[0];
	 	int ss[100];
	 	int ss_cur_pos = 0;
	 	ss[ss_cur_pos] = 1;
	 	bool first_test = true;
	 	for(int j = 1; j < n; ++j) {
	 		if(simple_s[j] == simple_s[j-1]) {
	 			// cout << "---" << endl;
	 			// cout << simple_s[j] << endl;
	 			// cout << simple_s[j-1] << endl;
		 		ss[ss_cur_pos]++;
	 		} else {
	 			ss_cur_pos++;
	 			cur_string = simple_s[j];
	 			ss[ss_cur_pos] = 1;
	 		}
	 	}
	 	unsigned long ans = 0;

	 	do {
	 		bool has_ans = true;
	 		bool aval_char[26];
	 		for(int k = 0; k < 26; ++k) {
	 			aval_char[k] = true;
	 		}
	 		for(int j = 0; j < n; ++j) {
	 			int str_size = simple_s[j].size();
	 			for(int k = 0; k < str_size; ++k) {
	 				int char_index = simple_s[j][k] - 'a'; 
	 				if(aval_char[char_index] == true) {
	 					aval_char[char_index] = false;	 					
	 				} else {
	 					if(k == 0 && simple_s[j][0] == simple_s[j-1][simple_s[j-1].size()-1]) {
	 						continue;
	 					} else {
	 						has_ans = false;
	 						break;
	 					}
	 				}
	 			}
	 			if(has_ans == false) {
	 				break;
	 			}
	 		}

	 		// if(has_ans) {
	 		// 	for(int j = 0; j < n; j++) {
	 		// 		cout << simple_s[j] << endl;
	 		// 	}
	 		// }

	 		// cout << "???" << endl;
	 		ans += has_ans;
	 		ans = ans % 1000000007;
	 	} while(next_permutation(simple_s, simple_s+n));

	 	for(int j = 0; j <= ss_cur_pos; j++) {
	 		ans =  ans * (factorial_mod(ss[j]));
	 		ans = ans % 1000000007;
	 	}
	 	cout << "Case #" << i+1 << ": " << ans << endl;
	}
	return 0;
}

	// 	// for(int j = 0; j < n; ++j) {
	// 	// 	cout << simple_s[j] << endl;
	// 	// }
	// 	// cout << "-----" << endl;
		// int same_string[100];
		// int ss_cur_pos = 0;
	// 	char char_link[24];
	// 	int cl_cur_pos = 0;
	// 	string cur_string = simple_s[0];
	// 	char_link[cl_cur_pos] = cur_string[cur_string.size()-1];
	// 	same_string[ss_cur_pos] = 1;
	// 	string unique_string[100];
	// 	unique_string[ss_cur_pos] = simple_s[0];
	// 	bool has_ans = true;
		
	// 	int breaks = 0;

	// 	for(int j = 1; j < n; ++j) {
	// 		if(simple_s[j] == cur_string) {
	// 			++same_string[ss_cur_pos];
	// 			if(cur_string.size() > 1){
	// 				has_ans = false;
	// 				break;
	// 			}
	// 		} else {
	// 			if(simple_s[j][0] < char_link[cl_cur_pos]) {
	// 				has_ans = false;
	// 				break;
	// 			} else {
	// 				if(simple_s[j][0] > char_link[cl_cur_pos]) {
	// 					++breaks;
	// 				}
	// 				++cl_cur_pos;
	// 				int ss_size = simple_s[j].size();
	// 				char_link[cl_cur_pos] = simple_s[j][ss_size-1];
	// 				cur_string = simple_s[j];
	// 				++ss_cur_pos;
	// 				same_string[ss_cur_pos] = 1;
	// 				unique_string[ss_cur_pos] = cur_string;
	// 			}
	// 		}
	// 	}
	// 	// for(int j = 0; j <= ss_cur_pos; ++j) {
	// 	// 	cout << same_string[j] << endl;
	// 	// }
	// 	if(has_ans == false) {
	// 		cout << "Case #" << i+1 << ": " << 0 << endl;
	// 	} else {
	// 		// cout << "here" << endl;
	// 		++breaks;
	// 		// cout << "breaks: "<< breaks << endl;

	// 		unsigned long facs[100];
	// 		unsigned long breaks_mod = factorial_mod(breaks);
	// 		// cout << breaks_mod << endl;
	// 		for(int j = 0; j <= ss_cur_pos; ++j) {
	// 			if(same_string[j] != 1) {
	// 				facs[j] = factorial_mod(same_string[j]);
	// 			} else {
	// 				facs[j] = same_string[j];
	// 			}
	// 			// cout << "facs" << j << ": " << facs[j] << endl;
 // 				breaks_mod = facs[j] * breaks_mod;
	// 			breaks_mod = breaks_mod % 1000000007;
	// 		}
	// 		cout << "Case #" << i+1 << ": " << breaks_mod << endl;
	// 	}
	// }
// 	return 0;
// }