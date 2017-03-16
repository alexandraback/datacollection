#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#ifdef DEBUG
#define Dprintf(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__);
#else
#define Dprintf(fmt, ...) 
#endif

typedef pair<int, int> P;

int main(int argc, char const* argv[])
{
	int T;
	cin >> T;
	for (int ii = 0; ii < T; ii++) {
		int N;
		cin >> N;
		vector<P> notouch;
		priority_queue<int, vector<int>, greater<int> > halfcleared;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			notouch.push_back(P(b, a));
		}
		sort(notouch.begin(), notouch.end());

		int star = 0;
		int ans = 0;
		bool cannot = false;
		while (!notouch.empty() || !halfcleared.empty()) {
			Dprintf("star = %d, ans = %d\n", star, ans);
			if (!halfcleared.empty()) {
				if (halfcleared.top() <= star) {
					Dprintf("cleared 2 rated after 1 rated (req: %d)\n", halfcleared.top());
					halfcleared.pop();
					++star;
					++ans;
					continue;
				}
			}
			if (!notouch.empty() && notouch.at(0).first <= star) {
				Dprintf("cleared 2 rated (req: %d)\n", notouch.at(0).first);
				star += 2;
				notouch.erase(notouch.begin());
				++ans;
				continue;
			}
			bool c = false;
			for (int i = notouch.size() - 1; i >= 0; i--) {
				if (notouch.at(i).second <= star) {
					Dprintf("cleared 1 rated (req: %d, 2rated: %d)\n", notouch.at(i).second, notouch.at(i).first);
					++star;
					halfcleared.push(notouch.at(i).first);
					notouch.erase(notouch.begin() + i);
					c = true;
					++ans;
					break;
				}
			}
			if(c) continue;

			cannot = true;
			break;
		}
		if (cannot) {
			printf("Case #%d: Too Bad\n", ii + 1);
		} else {
			printf("Case #%d: %d\n", ii + 1, ans);
		}
	}
	return 0;
}
