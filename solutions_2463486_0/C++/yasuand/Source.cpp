#include<iostream>
#include<vector>
using namespace std;

#define rep(i, from, to) for (i = from; i < to; ++i)
#define len(a) sizeof(a)/sizeof(*a)

int main()
{
	int t;
	cin >> t;
	int i, j;
	long long nums[] = {       0,       1,       2,       3,      11,      22,
						     101,     111,     121,     202,     212,    1001,
							1111,    2002,   10001,   10101,   10201,   11011,
						   11111,   11211,   20002,   20102,  100001,  101101,
						  110011,  111111,  200002, 1000001, 1001001, 1002001,
						 1010101, 1011101, 1012101, 1100011, 1101011, 1102011,
						 1110111, 1111111, 2000002, 2001002,10000001};
	rep (i, 0, len(nums)) {
		nums[i] *= nums[i];
	}
	rep (i, 0, t) {
		long long a, b;
		cin >> a >> b;
		for (j = 0; nums[j] < a; ++j);
		int result = 0;
		for (; nums[j] <= b; ++j, ++result);
		cout << "Case #" << i + 1 << ": " << result << "\n";
	}
	return 0;
}