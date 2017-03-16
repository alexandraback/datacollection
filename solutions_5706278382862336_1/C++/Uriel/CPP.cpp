//GCJ Round1A 2014-04-26 B
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

FILE* fw;

long long gcd(long long a, long long b) {
	if (a == b)
		return a;
	if ((a & 1) == 0) {
		if ((b & 1) == 0)
			return gcd(a >> 1, b >> 1) << 1;
		else
			return gcd(a >> 1, b);
	} else {
		if ((b & 1) == 0)
			return gcd(a, b >> 1);
		else
			return gcd(((a > b) ? (a - b) : (b - a)) >> 1, (a + b) >> 1);
	}
}

int main() {
	freopen("A-large.in", "r", stdin);
//	freopen("A-small-attempt0.in", "r", stdin);
	fw = fopen("A-l.txt", "w");
	int cse, g = 1, gen;
	long long a, b, tp;
	bool ok;
	scanf("%d", &cse);
	while (cse--) {
		scanf("%lld/%lld", &a, &b);
		tp = gcd(a, b);
		a /= tp;
		b /= tp;
		ok = true;
		tp = b;
		while (tp > 1) {
			if (tp & 1) {
				ok = false;
				break;
			}
			tp = tp / 2;
		}
		if (!ok) {
			fprintf(fw, "Case #%d: impossible\n", g++);
		} else {
			gen = 1;
			while (a * 2 < b) {
				a = a * 2;
				gen++;
			}
			if(gen <= 40) {
				fprintf(fw, "Case #%d: %d\n", g++, gen);
			}
			else {
				fprintf(fw, "Case #%d: impossible\n", g++);
			}
		}
	}
	fclose(fw);
	return 0;
}

