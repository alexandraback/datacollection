#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

typedef long long int64;

int64 query[10000][2], ans[10000][2], p[20000];
int sign[20000];
int T;
int64 data[] = {1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002, 10000001, 10011001, 10100101, 10111101, 11000011, 11011011, 11100111, 11111111, 20000002, 100000001, 100010001, 100020001, 100101001, 100111001, 100121001, 101000101, 101010101, 101020101, 101101101, 101111101, 110000011, 110010011, 110020011, 110101011, 110111011, 111000111, 111010111, 111101111, 111111111, 200000002, 200010002};

ifstream read("c.in");
ofstream write("c.out");

bool check(int64 x)
{
	int64 base = 1;
	for (; base < x; base *= 10);
	base /= 10;
	for (; x > 9; base /= 100) {
		int l = x / base, r = x % 10;
		if (l != r) return 0;
		x = (x - base * l) / 10;
	}
	return 1;
}

bool cmp(const int &x, const int &y)
{
	return p[x] < p[y];
}

void calc()
{	
	ofstream output("data.txt");
	int n = T << 1;
	int max = sqrt(p[sign[n - 1]]) + 3;
	int index = 0;
	int64 tot = 1;
	for (int64 i = 1; i < max; ++i) {
		int64 x = i * i;
		while (x > p[sign[index]]) {
			int bas = sign[index] >> 1, off = sign[index] & 1;
			ans[bas][off] = tot;
			if (++index >= n) return;
		}
		if (check(i) && check(x)) {
			++tot;
			output << i << ' ';
		}
		
	}
}

int main()
{
	read >> T;
	/*for (int i = 0; i < T; ++i) {
		read >> query[i][0] >> query[i][1];
		p[i << 1] = query[i][0] - 1;
		sign[i << 1] = i << 1;
		p[(i << 1) + 1] = query[i][1];
		sign[(i << 1) + 1] = (i << 1) + 1;
 	}
	sort(sign, sign + T * 2, cmp);*/

	for (int i = 0; i < T; ++i) {
		int64 A, B;
		read >> A >> B;
		int ans = 0;
		for (int j = 0; j < 71; ++j) {
			int64 x = data[j] * data[j];
			if (x >= A && x <= B)
				++ans;
		}
		write << "Case #" << i + 1 << ": " << ans << endl;
	}
	
	return 0;
}
