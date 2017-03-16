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
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0;i < t;++i) {
		int k, c,s;
		cin >> k >> c >> s;
		cout << "Case #" << i + 1 << ":";
		for (int q = 0;q < k;++q) {
			cout << " " << q + 1;
		}
		cout << endl;
	}
}
//I have used Boost library.if it isn't allowed,please tell me.