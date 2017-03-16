#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;
vector<long long> times;
long long reverse(long long input) {
	while(input % 10 == 0) {
		input /= 10;
	}
	long long ret = 0;
	while(input != 0) {
		int digit = input % 10;
		ret = ret * 10 + digit; 
		input /= 10;
	}
	
	return ret;
}
int num_digit(long long input) {
	int ret = 0; 
	while(input != 0) {
		ret ++;
		input /= 10;
	}
	return ret;
}


long long compute(long long cur, int digits) {
	cout << cur << " " << digits << endl;
	long long origin = cur;
	if(digits == 0){
		cerr << "digits == 0!!! sth went wrong" << endl;
		return numeric_limits<long long>::infinity();
	}
	if(digits == 1) {
		return cur;
	}
	long long min_same_digit = 1;
	for(int i = 1; i < digits; i++) {
		min_same_digit *= 10;
	}
	if(cur == min_same_digit) 
		return 1 + compute(cur-1, digits-1);
	int da = digits/2;
	int db = digits - da;
	long long num_b = 0; 
	long long num_a = 0; 
	long long exp = 1;
	for(int i = 0; i < db; i++) {
		int digit = cur % 10;
		num_b += digit*exp; 
		cur /= 10;
		exp *= 10;
	}
	num_a = cur;
	cout << num_a << " " << num_b << endl;

	long long min_first = 1;
	for(int i = 1; i < da; i++) {
		min_first *= 10;
	}
	if(num_a == min_first) {
		return num_b + compute(min_same_digit, digits);
	}
	
	if(num_b % 10 == 0) {
		return 1 + compute(origin -1, digits);
	}
	else {
		cout << "reverse " << reverse(num_a) << endl;
		return num_b + reverse(num_a) + compute(min_same_digit, digits);
	}

	
}

int main() {
	ifstream in("A-large.in");
	ofstream out;
	out.open("large.out");
	
	int t;
	in >> t;
	for(int i = 0; i < t; i++) {
		int n; 
		in >> n;
		int num = num_digit(n);
		int res = compute(n, num);

		out << "Case #" << i+1 << ": " << res << endl;
	}

	out.close();
	return 0;
}
