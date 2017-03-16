#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<int> pairing[2000001];
int powOf10[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

void precompute() {
	for (int i = 1; i <= 2000000; ++i) {
		int digCount = (int)log10(i) + 1;
		
		// do recycling on all digit separation
		for (int j = 1; j < digCount; ++j) {
			int right = i / powOf10[j];
			int left = (i % powOf10[j]) * (powOf10[digCount - j]);
			int result = left + right;
			
			if (result <= i) continue;
			
			// check any duplication
			bool found = false;
			for (int k = 0, n = pairing[i].size(); k < n; ++k) {
				if (result != pairing[i][k]) continue;
				
				found = true;
			}
			
			// no duplication! GOO!!!
			if (!found) {
				pairing[i].push_back(result);
			}
		}
	}
}

int main() {
	int ntc;
	
	precompute();
	
	scanf("%d", &ntc);
	
	for (int tc = 1; tc <= ntc; ++tc) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		int cnt = 0;
		for (int i = a; i <= b; ++i) {
			for (int j = 0, n = pairing[i].size(); j < n; ++j) {
				if (pairing[i][j] >= a && pairing[i][j] <= b) {
					++cnt;
				}
			}
		}
		
		printf("Case #%d: %d\n", tc, cnt);
	}
}
