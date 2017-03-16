#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

struct tribe {
	ll d, n;
	ll w, e;
	ll s, dd, dp, ds;

	bool operator < (const tribe & t2) const {
		if (d != t2.d)
			return d < t2.d;
		else if (n != t2.n)
			return n < t2.n;
		else if (w != t2.w)
			return w < t2.w;
		else if (e != t2.e)
			return e < t2.e;
		else if (dp != t2.dp)
			return dp < t2.dp;
		return false;
	}
};

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n;
		scanf("%d", &n);
		ll _wall[1001], *wall = _wall + 500;
		fill (_wall, _wall+1001, 0);

		vector<tribe> heap;
		for (int i=0; i<n; i++) {
			tribe t;
			scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d", &t.d, &t.n, &t.w, &t.e, &t.s, &t.dd, &t.dp, &t.ds);
			heap.push_back(t);

			t.n --;
			while (t.n > 0) {
				t.d += t.dd;
				t.s += t.ds;
				t.w += t.dp;
				t.e += t.dp;
				heap.push_back(t);
				t.n--;
			}
		}

		sort(heap.begin(), heap.end());
		/*for (unsigned i=0; i<heap.size(); i++)
			printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n", heap[i].d, heap[i].n, heap[i].w, heap[i].e, heap[i].s, heap[i].dd, heap[i].dp, heap[i].ds);*/

		ll attacks = 0;
		for (unsigned i = 0; i < heap.size(); ){
			ll d = heap[i].d;
			//printf("%I64d\n", d);
			unsigned ifin;

			for (ifin=i; ifin < heap.size(); ifin ++) {
				if (heap[ifin].d != d)
					break;

				tribe & t = heap[ifin];
				for (int j=t.w; j<t.e; j++) {
					if (wall[j] < t.s) {
						//printf(" %u\n", ifin);
						attacks ++;
						break;
					}
				}				
			}

			for (; i<ifin; i++) {
				tribe & t = heap[i];

				for (int j=t.w; j<t.e; j++) {
					if (wall[j] < t.s)
						wall[j] = t.s;
				}
			}
		}

		printf("Case #%d: %I64d\n", iC, attacks);
	}
	return 0;
}