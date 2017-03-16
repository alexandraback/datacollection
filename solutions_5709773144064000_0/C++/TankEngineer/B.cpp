#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		double curtime = 0, currate = 2;
		do {
			double nextfarmwin = c / currate + c / f;
			if (curtime + nextfarmwin > curtime + x / currate) {
				curtime += x / currate;
				break;
			} else {
				curtime += c / currate;
				currate += f;
			}
		} while (true);
		static int id = 0;
		printf("Case #%d: %.7f\n", ++id, curtime);
	}
	return 0;
}
