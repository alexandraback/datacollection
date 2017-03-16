#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <list>

using namespace std;

bool is_palindromes(long long x) {
	if(x>=0 && x<10) {
		return true;
	}
	stringstream ss;
	ss << x;
	string s = ss.str();
	int b = 0;
	int e = s.length()-1;
	while(b<e) {
		if(s[b] != s[e]) {
			return false;
		}
		b++;
		e--;
	}
	return true;
}

int main()
{
	vector<long long> table;
	long long max_data = 10009LL;
	for(long long i=0;i<max_data;i++) {
		long long square = i*i;
		if(is_palindromes(i) && is_palindromes(square)) {
			table.push_back(square);
			//cout << i << " " << square << endl;
		}	
	}
	int N=0;
	cin >> N;
	for(int n=1;n<=N;n++) {
		long long nx, ny;
		cin >> nx >> ny;
		int i = 0;
		int ix = 0;
		int iy = table.size();
		for(i=0;i<table.size();i++) {
			if(table[i]>=nx) {
				ix = i;	
				break;
			}
		}
		for(i=table.size()-1;i>=0;i--) {
			if(table[i]<=ny) {
				iy = i;
				break;
			}	
		}
		int result = max(0, iy-ix+1);
		cout << "Case #" << n << ": " << result << endl;
	}
	return 0;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
