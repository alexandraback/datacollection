#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>
#include <sstream>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

double p[100005];

int main() 
{
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	int TestCase;
	cin >> TestCase;
	for (int T = 1; T <= TestCase; T++) {
		int A, B;
		cin >> A >> B;
		for (int i = 0; i < A; i++) cin >> p[i];

		double res = min(B+2, A+B+1), prob = 1.0;
		for (int i = 0; i < A; i++) {
			prob *= p[i];
			double num = (B-A+(A-i-1)*2+1);
			res = min(res, prob*num + (1.0-prob)*(num+B+1)); 
		}

		printf("Case #%d: %lf\n", T, res);
	}
}