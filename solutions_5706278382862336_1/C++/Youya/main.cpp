#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;
long gcd(long a, long b)
{
	long r;
	while(b) {
		r = a;
		a = b;
		b = r % b;
	}
	return a < 0?-a:a;
}

bool power_2(long a)
{
	for (int i = 0; i <=40; i++){
		if (a == 1)
			return true;
		if (a % 2 != 0)
			return false;
		else {
			a = a/2;
		}
	}
	return false;
}

int main()
{
	long TC;
	cin >> TC;
	for (long T = 1; T <= TC; T++) {
		string s;
		long P, Q;
		scanf("%ld/%ld",&P, &Q);
		long g = gcd(P, Q);
		if (!power_2(Q/g))
			printf("Case #%d: impossible\n", T);
		else{
			int c = 0;
			double t = (double)P/(double)Q;
			while(t < 1) {
				c++;
				t *= 2;
			}
			printf("Case #%d: %d\n", T, c);
		}
	}

	return 0;
}
