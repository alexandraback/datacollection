#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long     LL;

#define For(i,a,b)    for(int i=(a);i<(b);++i)
#define rep(i,n)      For(i,0,(n))

LL create_jamcoin(int N, int gen)
{
	LL cand = (LL(1) << (N - 1)) | 0x01;

	for(int i = 1 ; gen ; i += 2, gen >>= 1)
		if(gen & 0x01)
			cand |= (LL(0x03) << i);
	return cand;
}

string to_bin(LL i)
{
	string result;
	do {
		result += '0' + (i & 0x01);
		i >>= 1;
	} while(i);

	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	int T;
	int N, J;

	cin >> T;			// 1
	cin >> N >> J;		// (16, 50) or (32, 500)

	cout << "Case #1:" << endl;
	rep(i, J) {
		LL jamcoin = create_jamcoin(N, i);
		cout << to_bin(jamcoin) << " 3 2 5 2 7 2 3 2 11" << endl;
	}
}
