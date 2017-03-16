#include <iostream>
#include <queue>
using namespace std;

int solve(int* list, int x) {
    if (x == 0) return 0;
    if (list[x] == 0) return solve(list, x-1);
    
    int best = x;
    int q = list[x];
    list[x] = 0;
    for (int n = 1; n <= x/2; ++n) {
        list[n] += q;
        list[x-n] += q;
        best = min(best, solve(list, x-1)+q);
        list[n] -= q;
        list[x-n] -= q;
    }
    list[x] = q;
	return best;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
        int list[1002] = {0};
		int n;
		cin >> n;
		while (n--) {
			int x;
			cin >> x;
			list[x] += 1;
		}
		cout << "Case #" << i << ": " << solve(list, 1000) << endl;
	}
}

