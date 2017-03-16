#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

int T;
int n;
vector <ii> seq;

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d: ", tc);
		scanf("%d", &n);
		seq.clear();
		while (n--) {
			int d, h, m; scanf("%d %d %d", &d, &h, &m);
			for (int i = 0; i < h; i++)
				seq.push_back(ii(d, m + i));
		}
		sort(seq.begin(), seq.end());
		if (seq.size() <= 1) printf("0\n");
		else {
			bool ok = (360 - seq[0].first) * seq[1].second < (720 - seq[1].first) * seq[0].second;
			if (ok) printf("0\n");
			else printf("2\n");
		}
	}
	return 0;
}