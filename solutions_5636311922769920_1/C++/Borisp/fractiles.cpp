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

long long getNumber(const vector<int>& v, int k) {
	long long res = 0;
	long long fact = 1;
	for (int i = (int)v.size() - 1; i>= 0; i--) {
		res = (res + v[i] * fact);
		fact = fact * k;
	}
	return res + 1;
}

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d:", testCounter + 1);
		int k, c, s;
		cin >> k >> c >> s;
		if (k / c > s) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		bool covered = false;
		int idx = 0;
		while(idx < k) {
			vector<int> chosen;
			for (int i = 0; idx < k && i < c; i++) {
				chosen.push_back(idx++);
			}
			while(chosen.size() < c) {
				chosen.push_back(0);
			}
			cout << " " << getNumber(chosen, k);
		}
		cout << endl;
	}
	return 0;
}
