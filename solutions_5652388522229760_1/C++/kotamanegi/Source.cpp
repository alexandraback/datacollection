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
int main() {
	int t;
	cin >> t;
	int n;
	for (int i = 0;i < t;++i) {
		cin >> n;
		map<char, bool> hoge;
		cout << "Case #" << i + 1 << ": ";
		if (n == 0) {
			cout << "INSOMNIA" << endl;
			goto ok;
		}
		int nn = n;
		while (true) {
			string hogehoge = to_string(n);
			for (int q = 0;q < hogehoge.length();++q) {
				hoge[hogehoge[q]] = true;
			}
			for (int q = (int)'0';q <= (int)'9';++q) {
				if (hoge[(char)q] != true) goto faiel;
			}
			cout << n << endl;
			break;
		faiel:;
			n += nn;
		}
	ok:;
	}
}
//I used google chrome to copy and paste input,and redirect by cmd.finally,I entered enter.