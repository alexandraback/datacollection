#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int in() {
	int a;
	scanf("%d", &a);
	return a;
}

int main() {
	int T = in();
	for (int t = 0; t < T; t++) {
		int D = in();
		vector<int> panc(D);
		for (int i = 0; i < D; i++) {
			panc[i] = in();
		}
		sort(panc.begin(), panc.end());
		
		int minmin = 1001001001;
		for (int eat = 1; eat <= 1000; eat++) {
			int spec = 0;
			for (int i = 0; i < D; i++) {
				spec += (int)floor(((double)panc[i] - 1e-9) / eat);
			}
			if (eat + spec < minmin) {
				minmin = eat + spec;
			}
		}
		
		printf("Case #%d: %d\n", t+1, minmin);
	}
}
