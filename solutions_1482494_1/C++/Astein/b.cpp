#include <vector>
#include <cstdio>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int n;
		scanf("%d", &n);
		vector<int> one(n), two(n), check(n);

		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &one[i], &two[i]);
			check[i] = 0;
		}

		int num_star = 0;
		bool ispos = true;
		int turn = 0;
		while (true) {
			if (num_star == 2 * n) break;
			turn++;
			// 별이 두개 
			for (int i = 0; i < n; ++i) {
				if (check[i] == 0 && num_star >= two[i]) {
					check[i] = 2;
					num_star += 2;
					goto done;
				}
			}
			// 별이 한개 -> 두개 
			for (int i = 0; i < n; ++i) {
				if (check[i] == 1 && num_star >= two[i]) {
					check[i] = 2;
					num_star ++;
					goto done;
				}
			}
			// 별이 한개
			{
				int pp = -1, maxt = -1;
				for (int i = 0; i < n; ++i) {
					if (check[i] == 0 && num_star >= one[i]) {
						if (maxt < two[i]) {
							maxt = two[i];
							pp = i;
						}
					}
				}
				if (pp == -1) {
					ispos = false;
					break;
				} else {
					check[pp] = 1;
					num_star++;
				}
			}
done: ;
		}
		if (!ispos) {
			printf("Case #%d: Too Bad\n", cn);
		} else {
			printf("Case #%d: %d\n", cn, turn);
		}
	}
}
