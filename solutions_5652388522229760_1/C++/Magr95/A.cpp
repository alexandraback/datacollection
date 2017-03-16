#include <cstdio>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
	unordered_set<int> s;
	//freopen("A-small-attempt0.in.txt", "r", stdin);
	freopen("A-large.in.txt", "r", stdin);
	freopen("large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		s.clear();
		int sol = 0, N, last = 0;
		//for (N = 1; N <= 1000000; N++) {
		scanf("%d", &N);
		if (N == 0) {
			printf("Case #%d: INSOMNIA\n", i);
			continue;
		}
			//s.clear();
			//printf("%d", N);
			int j = 1;
			while (s.size() < 10) {
				int val = N*j;
				//if (val < 0) {printf("T:%d:\n", N); break;} 
				while (val != 0) {
					s.insert(val%10);
					val/=10;
				}
				last = N*j;
				sol++;
				j++;
			}
			/*for (auto it = s.begin(); it != s.end(); ++it) {
				printf("%d ", *it);
			}*/
		//}
		printf("Case #%d: %d\n", i, last);
	}
	return 0;
}