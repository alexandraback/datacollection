#include <cstdio>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	int T, x = 1;
	scanf("%d\n", &T);
	while (T--) {
		int J, P, S, K;
		scanf("%d %d %d %d\n", &J, &P, &S, &K);
		vector< tuple<int, int, int> > outfits;
		unordered_map<int, int> worn;
		unordered_map<int, int> full;

		for (int j = 1; j <= J; ++j) {
			for (int p = 1; p <= P; ++p) {
				for (int s = 1; s <= S; ++s) {
					if (j == p || p == s)
						continue;
					int ts[] = {
						j * 1000000 + p * 1000 + 0,
						j * 1000000 + 0 * 1000 + s,
						0 * 1000000 + p * 1000 + s,
					};
					bool ok = true;
					for (auto &&t : ts) {
						auto it = worn.find(t);
						if (it == worn.end()) {
							worn[t] = 0;
						}
						if (worn[t]+1 > K) { 
							ok = false;
							break;
						}
					}
					if (ok) { 
						for (auto &&t : ts) {
							worn[t]++;
						}
						full[j * 1000000 + p * 1000 + s] = 1;
						outfits.emplace_back(j, p, s);
					}
				}
			}
		}

		for (int j = 1; j <= J; ++j) {
			for (int p = 1; p <= P; ++p) {
				for (int s = 1; s <= S; ++s) {
					int f = j * 1000000 + p * 1000 + s;
					auto it = full.find(f);
					if (it != full.end())
						continue;
					int ts[] = {
						j * 1000000 + p * 1000 + 0,
						j * 1000000 + 0 * 1000 + s,
						0 * 1000000 + p * 1000 + s,
					};
					bool ok = true;
					for (auto &&t : ts) {
						auto it = worn.find(t);
						if (it == worn.end()) {
							worn[t] = 0;
						}
						if (worn[t]+1 > K) { 
							ok = false;
							break;
						}
					}
					if (ok) { 
						for (auto &&t : ts) {
							worn[t]++;
						}
						outfits.emplace_back(j, p, s);
					}
				}
			}
		}

		printf("Case #%d: %ld\n", x++, outfits.size());
		for (auto &&t : outfits)
			printf("%d %d %d\n", get<0>(t), get<1>(t), get<2>(t));

	}

	return 0;
}
