#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <array>
#include <string>
#include <deque>
#include <list>
#include <numeric>
#include <limits>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <functional>

using namespace std;

int bitCount(long long n){
	int res = 0;
	do{
		++res;
		n = n / 10;
	} while (n != 0);

	return res;
}

long long pow(int e){
	long long res = 1;
	for (int i = 0; i < e; ++i){
		res *= 10;
	}
	return res;
}

long long reverse(long long n){
	string s = to_string(n);
	reverse(s.begin(), s.end());
	return stoll(s);
}

void comp(int tc){
	long long N;
	cin >> N;

	long long res = 0;
	if (N <= 10){
		res = N;
	}
	else{
		if (N % 10 == 0){
			res = 1;
			--N;
		}
		int curBit = 2, targetBit = bitCount(N);
		res += 10;
		
		while (curBit < targetBit){
			res += pow(curBit / 2) + pow((curBit + 1) / 2) - 1;
			++curBit;
		}		

		long long one = res + N - pow(targetBit - 1);

		long long mod = pow(targetBit / 2);
		long long rhs = N % mod;
		long long lhs = reverse(N / mod);

		long long two = res + lhs + rhs;

		mod = pow((targetBit + 1) / 2);
		rhs = N % mod;
		lhs = reverse(N / mod);
		long long three = res + lhs + rhs;

		res = min({ one, two, three });
	}

	cout << "Case #" << tc << ": " << res << endl;
}

int main(){
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i){
		comp(i);
	}
}