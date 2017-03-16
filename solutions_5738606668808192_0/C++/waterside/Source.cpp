#define _CRT_SECURE_NO_WARNINGS // scanf(), gets() (needed for Visual C++)

#include <cassert>

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

using namespace std;

#define MEMSET(x, WITH) memset(x, (WITH), sizeof(x))
#define FOR(i, E) for (int i=0; i<(E); i++)

typedef long long ll;
//const ll MOD = 1000000007;
//const double PI = atan(1) * 4;





//const int N = 16;
//const int J = 50;


ll getValue(ll repr, int base) {
	if (repr == 0) return 0;

	return (repr&1) + base * getValue(repr>>1, base);
}

string getString(ll repr) {
	if (repr == 0) return "0";
	if (repr == 1) return "1";

	return getString(repr>>1) + getString(repr&1);
}




int main() {
	freopen("output.txt", "w", stdout);
	puts("Case #1:");

	ll a = (1<<8) + 1;
	ll b = (1<<7) + 1;
	for (ll mask=0; mask<50; mask++) {
		ll bb = b | (mask<<1);
		ll jamcoin = a * bb;

		cout << getString(jamcoin) << " ";
		for (int base=2; base<=10; base++)
			cout << getValue(a, base) << " ";
		cout << endl;
	}








	return 0;
}
