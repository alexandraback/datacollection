#include <cstdio>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

void solve()
{
	static int casenr = 1;
	printf("Case #%d: ", casenr++);
	
	int n; scanf("%d", &n);
	
	if (n == 0) {
		puts("INSOMNIA");
		return;
	}
	
	set<int> have;
	int x = 0;
	int result = 0;
	while (true) {
		x += n; result += 1;
		int i = x;
		while (i > 0) {
			have.insert(i%10);
			i /= 10;
		}
		if (have.size() == 10) {
			result = x;
			break;
		}
	}
	
	//printf("%-10d %-10d\n", result, result / n);
	printf("%d\n", result);
}

int main() {
	int T; scanf("%d", &T);
	while (T-- > 0) {
		solve();
	}
	return 0;
}
