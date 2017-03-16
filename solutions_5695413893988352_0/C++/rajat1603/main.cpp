#include "bits/stdc++.h"
using namespace std;
int t;
int tc = 0;
string str1;
string str2;
int n;
long long ans;
long long ans1;
long long ans2;
void solve(int pos , long long num1 , long long num2){
	if(pos == n){
		long long dif = max(num1 - num2 , num2 - num1);
		if(dif < ans){
			ans = dif;
			ans1 = num1;
			ans2 = num2;
		}
		else if(dif == ans){
			if(num1 < ans1){
				ans1 = num1;
				ans2 = num2;
			}
			else if(num1 == ans1){
				if(num2 < ans2){
					ans2 = num2;
				}
			}
		}
		return;
	}
	if(str1[pos] == '?' && str2[pos] == '?'){
		for(int i = 0 ; i < 10 ; ++i){
			for(int j = 0 ; j < 10 ; ++j){
				solve(pos + 1 , num1 * 10 + i , num2 * 10 + j);
			}
		}
	}
	else if(str1[pos] == '?' && str2[pos] != '?'){
		int dig = str2[pos] - '0';
		for(int i = 0 ; i < 10 ; ++i){
			solve(pos + 1 , num1 * 10 + i , num2 * 10 + dig);
		}
	}
	else if(str1[pos] != '?' && str2[pos] == '?'){
		int dig = str1[pos] - '0';
		for(int i = 0 ; i < 10 ; ++i){
			solve(pos + 1 , num1 * 10 + dig , num2 * 10 + i);
		}
	}
	else{
		int dig1 = str1[pos] - '0';
		int dig2 = str2[pos] - '0';
		solve(pos + 1 , num1 * 10 + dig1 , num2 * 10 + dig2);
	}
}
int main(){
	cin >> t;
	while(t--){
		++tc;
		cout << "Case #" << tc << ": "; 
		str1 = "";
		str2 = "";
		cin >> str1 >> str2;
		n = str1.size();
		ans = 4e18;
		solve(0 , 0 , 0);
		string answer1 = to_string(ans1);
		string answer2 = to_string(ans2);
		while(answer1.size() < n){
			answer1 = "0" + answer1;
		}
		while(answer2.size() < n){
			answer2 = "0" + answer2;
		}
		cout << answer1 << " " << answer2 << "\n";
	}
}