#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

vector<int> getDigits(long long number) {
	vector<int> toRet;
	while (number > 0) {
		toRet.push_back(number % 10);
		number /= 10;
	}
	return toRet;
}

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);

		long long n;
		cin >> n;
		if (n == 0) {
			cout << "INSOMNIA" << endl;
			continue;
		}

		set<int> digits;
		long long i;
		for (i = 1; digits.size() < 10; i++) {
			vector<int> newDigits = getDigits(i * n);
			digits.insert(newDigits.begin(), newDigits.end());
		}
		cout << (i - 1) * n << endl;
	}
	return 0;
}
