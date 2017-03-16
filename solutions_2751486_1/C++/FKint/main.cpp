#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <bitset>


using namespace std;
bool consonant(char c){
	if(c == 'a' || c == 'e'  || c == 'i' || c == 'o' || c == 'u')
		return false;
	return true;
}
int main(){
	int T;
	cin >> T;
	for(int curr_case = 1; curr_case <= T; ++curr_case){
		string s;
		cin >> s;
		int n;
		cin >> n;
		int l = s.length();
		int conscons = 0;
		int last_good_start = -1;
		long long amount = 0;
		for(int i = 0; i < s.length(); ++i){
			if(consonant(s[i])){
				++conscons;
				if(conscons >= n){
					last_good_start = i-n+1;
				}
			}else{
				conscons = 0;
			}
			amount += (last_good_start+1);
		}
		printf("Case #%d: %lld\n", curr_case, amount);
	}
	return 0;
}
