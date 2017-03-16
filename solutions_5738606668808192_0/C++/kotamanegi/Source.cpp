#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define  _SCL_SECURE_NO_WARNINGS
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
//Boost
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <boost/random.hpp>
using namespace std;
namespace mp = boost::multiprecision;
#define REP(a,b) for(long long a = 0;a < b;++a)
string number_tostring(mp::cpp_int number) {
	string ans;
	while (true) {
		if (number == 0) break;
		if (number % 2 == 1) {
			ans.push_back('1');
		}
		else {
			ans.push_back('0');
		}
		number /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
mp::cpp_int to_base(string now_base, int base) {
	mp::cpp_int n = 1;
	mp::cpp_int ans = 0;
	for (int i = now_base.length() - 1;i >= 0;--i) {
		if (now_base[i] == '1') {
			ans += n;
		}
		n *= base;
	}
	return ans;
}
int main() {
	int t;
	boost::random::mt19937 gen;
	scanf("%d", &t);
	for (int i = 0;i < t;++i) {
		int n, j;
		scanf("%d%d", &n, &j);
		cout << "Case #1:" << endl;
		mp::cpp_int currently_search = 1;
		for (int i = 0;i < n - 1;++i) {
			currently_search *= 2;
		}
		currently_search += 1;
		int counter = 0;
		while (true) {
			vector<mp::cpp_int> right;
			if (counter == j) break;
			string hoge = number_tostring(currently_search);
			for (int i = 2;i <= 10;++i) {
				mp::cpp_int hogehoge = to_base(hoge, i);
				if (mp::miller_rabin_test(hogehoge, 50,gen)) goto failed;
			}
			for (int i = 2;i <= 10;++i) {
				mp::cpp_int hogehoge = to_base(hoge, i);
				for (mp::cpp_int q = 2;q >= 0;q += 1) {
					if (hogehoge%q == 0) right.push_back(q);
					if (hogehoge%q == 0) break;
					if (q == 100000) goto failed;
				}
			}
			cout << hoge;
			for (int i = 2;i <= 10;++i) {
				cout << " " << right[i - 2];
			}
			cout << endl;
			counter++;
		failed:;
			currently_search += 2;
		}
	}
}
//I have used Boost library.if it isn't allowed,please tell me.