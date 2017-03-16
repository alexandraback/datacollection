#include <cstdio>
#include <vector>

using namespace std;

vector <int> coins;
bool seen[31];

int fully(int x) {
	for(int i = 1; i <= x; i ++)
		if(!seen[i])
			return i;
	return 0;
}

int main() {
	int T;
	scanf(" %d", &T);
	for(int z = 0; z < T; z ++) {
		int c, d, v;
		coins.clear();
		for(int i = 0; i < 31; i ++)
			seen[i] = false;
		scanf(" %d %d %d", &c, &d, &v);
		for(int i = 0; i < d; i ++) {
			int temp;
			scanf(" %d", &temp);
			coins.push_back(temp);
		}
		for(int i = 0; i < (1 << d); i ++) {
			int sum = 0;
			for(int j = 0; j < d; j ++) {
				if(i & (1 << j))
					sum += coins[j];
			}
			seen[sum] = true;
		}
		int ans = 0;
		while(fully(v)) {
			int newc = fully(v);
			coins.push_back(newc);
			d ++;
			ans ++;
			for(int i = 0; i < (1 << d); i ++) {
				int sum = 0;
				for(int j = 0; j < d; j ++) {
					if(i & (1 << j))
						sum += coins[j];
				}
				seen[sum] = true;
			}
		}
		printf("Case #%d: %d\n", z + 1, ans);
	}
	return 0;
}
