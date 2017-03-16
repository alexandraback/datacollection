#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include<map>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
string s;
bool check() {
	for (int i = 0;i < s.length();++i) {
		if (s[i] == '-') return false;
	}
	return true;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;++i) {
		cin >> s;
		int cnt = 0;
		while (true) {
			if (check()) break;
			cnt++;
			for (int i = 1;i < s.length();++i) {
				if (s[i] != s[i - 1]) {
					for (int q = 0;q < i;++q) {
						if (s[q] == '-') {
							s[q] = '+';
						}
						else {
							s[q] = '-';
						}
					}
					goto fail;
				}
			}
			break;
		fail:;
		}
		cout << "Case " << "#" << i + 1 << ": " << cnt << endl;
	}
}
//I used google chrome to copy and paste input,and redirect by cmd.finally,I entered enter.