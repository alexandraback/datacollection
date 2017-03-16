#define _CRT_SECURE_NO_WARNINGS
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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cstdint>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
string ans[2] = { "POSSIBLE","IMPOSSIBLE" };
string two_sin(long long hoge,int wop){//4-2
	string ans;
	while (hoge != 0) {
		if (hoge % 2 == 1) {
			ans.push_back('1');
		}
		else {
			ans.push_back('0');
		}
		hoge /= 2;
	}
	string wow;
	int waw = wop;
	int wq = ans.length();
	if (wq - waw < 0) {
		for (int i = 0;i < wop - ans.length();++i) {
			wow.push_back('0');
		}
	}
	return ans+wow;
}
int main() {
	int t;
	cin >> t;
	for (int testing = 1;testing <= t;++testing) {
		cout << "Case #" << testing << ":" << " ";
		int b;
		long long m;
		cin >> b >> m;
			//CAN DO IT
			string wow = two_sin(m,b-2);
			if (wow.length() > b - 1) {
				cout << ans[1] << endl;
				goto ok;
			}
			if (wow.length() == b-1) {
				for (int i = wow.length() - 2;i >= 0;--i) {
					if (wow[i] == '1') {
						cout << ans[1] << endl;
						goto ok;
					}
				}
				cout << ans[0] << endl;
				for (int i = 0;i < b;++i) {
					for (int q = 0;q < i+1;++q) {
						cout << "0";
					}
					for (int q = i+1;q < b;++q) {
						cout << "1";
					}
					cout << endl;
				}
				goto ok;
			}
			cout << ans[0] << endl;
			cout << "0";
			for (int i = 1;i < b - 1;++i) {
				cout << "1";
			}
			cout << "0" << endl;
			for (int i = 1;i < b-1;++i) {
				for (int q = 0;q < i + 1;++q) {
					cout << "0";
				}
				for (int q = i + 1;q < b - 1;++q) {
					cout << "1";
				}
				if (wow[i-1] == '0') {
					cout << "0";
				}
				else {
					cout << "1";
				}
				cout << endl;
			}
			for (int i = 0;i < b;++i) {
				cout << "0";
			}
			cout << endl;
		ok:;
		}
	}