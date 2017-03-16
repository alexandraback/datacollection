#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T, X;
  cin >> T;
  for (int t=1;t<=T;t++) {
		double C, F, X;
		cin >> C >> F >> X;
		double prod = 2;
		double ans = X/prod, time=0;
		while (true) {
			time += C/prod; // time to buy another farm...
			prod+=F;

			double newans = X/prod + time;
			if (ans > newans) ans=newans;
			else break;
		}
		printf("Case #%d: ", t);
		printf("%.10f\n", ans);
	}

  return 0;
}
