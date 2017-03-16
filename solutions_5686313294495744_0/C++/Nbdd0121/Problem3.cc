#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <unordered_set>

char buffer[21];

int main(void) {
	int cases;
	scanf("%d", &cases);
	for (int c = 1; c <= cases; c++) {
		int topics;
		scanf("%d", &topics);

		int count = 0;
		std::unordered_set<std::string> fmap;
		std::unordered_set<std::string> smap;

		for (int t = 0; t < topics; t++) {
			scanf("%s", buffer);
			std::string first = buffer;
			scanf("%s", buffer);
			std::string second = buffer;
			if (fmap.find(first) != fmap.end() && smap.find(second) != smap.end()) {
				count++;
			}
			fmap.insert(first);
			smap.insert(second);
		}

		printf("Case #%d: %d\n", c, count);
	}
	return 0;
}