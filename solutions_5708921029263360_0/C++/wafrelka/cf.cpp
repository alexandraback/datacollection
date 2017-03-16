#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int testcases;

	scanf("%d", &testcases);

	for(int case_num = 1; case_num <= testcases; ++case_num) {

		int a, b, c, k;

		scanf("%d%d%d%d", &a, &b, &c, &k);

		unsigned int ans = 0;
		int max_count = 0;

		for(unsigned int bit = 0; bit < (1 << (a * b * c)); ++bit) {

			bool ok = true;

			for(int x = 0; ok && x < a; ++x) {
				for(int y = 0; y < b; ++y) {
					int v = 0;
					for(int z = 0; z < c; ++z) {
						int s = (x * b * c) + (y * c) + z;
						v += (bit >> s) & 1;
					}
					if(v > k) {
						ok = false;
						break;
					}
				}
			}

			for(int x = 0; ok && x < a; ++x) {
				for(int z = 0; z < c; ++z) {
					int v = 0;
					for(int y = 0; y < b; ++y) {
						int s = (x * b * c) + (y * c) + z;
						v += (bit >> s) & 1;
					}
					if(v > k) {
						ok = false;
						break;
					}
				}
			}

			for(int y = 0; ok && y < b; ++y) {
				for(int z = 0; z < c; ++z) {
					int v = 0;
					for(int x = 0; x < a; ++x) {
						int s = (x * b * c) + (y * c) + z;
						v += (bit >> s) & 1;
					}
					if(v > k) {
						ok = false;
						break;
					}
				}
			}

			if(!ok)
				continue;

			int count = __builtin_popcount(bit);

			if(max_count < count) {
				max_count = count;
				ans = bit;
			}
		}

		printf("Case #%d: %d\n", case_num, max_count);
		for(int x = 0; x < a; ++x) {
			for(int y = 0; y < b; ++y) {
				for(int z = 0; z < c; ++z) {
					const int s = (x * b * c) + (y * c) + z;
					if((ans >> s) & 1)
						printf("%d %d %d\n", x + 1, y + 1, z + 1);
				}
			}
		}
	}

	return 0;
}
