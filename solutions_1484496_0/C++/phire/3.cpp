#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

#define foreach(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

int a[20];

//struct Answer{
//	Answer() : cLeft(0), cRight(0) { }
//	int cLeft;
//	int cRight;
//	int left[20];
//	int right[20];
//};

char dp[21][4*20*100000];
int ok(int c, int diff, int& maskLeft, int& maskRight)
{
	if (diff == 0 && maskLeft && maskRight) {
		maskLeft <<= (20 - c);
		maskRight <<= (20 - c);
		return true;
	}

	if (c == 20)
		return 0;

	if (dp[c][diff + 20*100000])
		return false;

	c++;
	maskLeft <<= 1;
	maskRight <<= 1;
	if (ok(c, diff, maskLeft, maskRight))
		return true;
	maskLeft |= 1;
	if (ok(c, diff + a[c-1], maskLeft, maskRight))
		return true;
	maskLeft ^= 1;
	maskRight |= 1;
	if (ok(c, diff - a[c-1], maskLeft, maskRight))
		return true;
	maskLeft >>= 1;
	maskRight >>= 1;
	dp[c-1][diff + 20*100000] = 1;
	return false;
}

int main(int argc, const char* argv[])
{
	int T;
	cin >> T;
	for(size_t i = 1; i <= T; ++i) {
		int N;
		cin >> N;
		assert(N == 20);
		for (int j = 0; j < N; j++)
			cin >> a[j];
		memset(dp, 0, sizeof(dp));
		int mask1 = 0, mask2 = 0;
		cout << "Case #" << i << ":" << endl;
		if (ok(0, 0, mask1, mask2)) {
			for (int j = 0; j < N; j++) {
				if ((1 << j) & mask1)
					cout << a[19 - j] << ' ';
			}
			cout << endl;
			for (int j = 0; j < N; j++) {
				if ((1 << j) & mask2)
					cout << a[19 - j] << ' ';
			}
			cout << endl;
		} else {
			cout << "Impossible" << endl;
		}

	}
    return 0;
}
