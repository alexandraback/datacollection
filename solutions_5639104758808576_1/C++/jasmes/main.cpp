#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <functional>

using namespace std;

#define upto(i,n) for(int i = 0; i<n; ++i)


int main() {
	string s;
	int t, n;
	int cnt, sum;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		cin >> s;
		cnt = 0;
		sum = 0;
		for (int i = 0; i < s.size(); i++) {
			if (cnt < i) {
				sum += i - cnt;
				cnt = i;
			} 
			cnt += (s[i] - '0');
		}


		cout << "Case #" << tc << ": " << sum << endl;
	}


	return 0;
}
