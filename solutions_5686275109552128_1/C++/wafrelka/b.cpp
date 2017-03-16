#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

bool ok(const int mi, const vector<int> &p)
{
	for(int s = 0; s < mi; ++s) {

		const int eat = mi - s;
		priority_queue<int> q;

		for(auto x : p) {
			if(x > eat)
				q.push(x);
		}

		for(int i = 0; i < s; ++i) {
			if(q.empty())
				break;
			const int v = q.top();
			const int w = v - eat;
			q.pop();
			if(w > eat)
				q.push(w);
		}

		if(q.empty())
			return true;
	}

	return false;
}

int main()
{
	int test_case;

	scanf("%d", &test_case);

	for(int case_num = 1; case_num <= test_case; ++case_num) {

		int d;
		vector<int> p;

		scanf("%d", &d);
		p.resize(d);
		for(int i = 0; i < d; ++i)
			scanf("%d", &p[i]);

		// lb: ng, ub: ok;
		int lb = 0, ub = 1048;

		while(ub - lb > 1) {

			const int mid = (ub + lb) / 2;

			if(ok(mid, p))
				ub = mid;
			else
				lb = mid;
		}

		const int ans = ub;

		printf("Case #%d: %d\n", case_num, ans);
	}

	return 0;
}
