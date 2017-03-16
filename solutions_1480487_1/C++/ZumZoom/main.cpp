#include <iostream> 
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set> 
#include <vector>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

const int INF = 2147483647;
const double EPS = 1E-10;

int main() { 
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int n, sum = 0;
		cin >> n;
		vector <int> S(n);
		for(int i = 0; i < n; ++i) {
			cin >> S[i];
			sum += S[i];
		}
		printf("Case #%d: ", t + 1);
		for(int i = 0; i < n; ++i) {
			double L = 0, R = 1;
			for(int j = 0; j < 100; ++j) {
				double M = (L + R) / 2;
				double res = M*sum + S[i];
				bool fail = true;
				double volume = M;
				for(int k = 0; k < n; ++k)
					if(k != i)
						volume += max(0., (res - S[k])/sum);
				volume += EPS;
				if(volume > 1)
					R = M;
				else
					L = M;
			}
			printf("%.6lf ", L*100);
		}
		printf("\n");

	}

	return 0;
} 