#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long HUGE;
vector<HUGE> matches;
map<HUGE, long> numMatches;

vector<int> getDigits(HUGE num){
	vector<int> digits;
	while(num != 0){
		digits.push_back(num%10);
		num /= 10;
	}
	return digits;
}

bool isPalindrome(HUGE num){
	vector<int> digits = getDigits(num);
	int start = 0;
	int end   = digits.size() - 1;
	while(start < digits.size()/2){
		if(digits[start] != digits[end])
			return false;
		start++;
		end--;
	}
	return true;
}

void findMatches(){
	for(HUGE i = 1; i <= 10000000; i++){
		if(isPalindrome(i) && (isPalindrome(i*i))){
			//cout << (i*i) << endl;
			matches.push_back(i*i);
		}
	}
	
	long count = 0;
	for(int i = 0; i < matches.size(); i++){
		count++;
		numMatches.insert(pair<HUGE, long>(matches[i], count));
	}
}

long getNumMatches(HUGE upper){
	vector<HUGE>::iterator iter = lower_bound(matches.begin(), matches.end(), upper);
	if(*iter == upper){
		return numMatches.find(*iter)->second;
	} else {
		iter--;
		return numMatches.find(*iter)->second;
	}
}


long solve(HUGE A, HUGE B){
	if(A == 1){
		return getNumMatches(B);
	} else {
		return getNumMatches(B) - getNumMatches(A-1);
	}
	return 0;
}

int main(){
	findMatches();
	int T; cin >> T;
	for(int i = 0; i < T; i++){
		HUGE A, B; cin >> A; cin >> B;
		cout << "Case #" << (i+1) << ": " << solve(A,B) << endl;
	}
}
