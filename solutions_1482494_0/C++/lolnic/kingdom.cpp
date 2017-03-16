#include <cstdio>
#include <algorithm>
#include <climits>
#define MAX_N 1005
using namespace std;

struct City {
	int id, req;
	const bool operator< (const City& c) const {
		return req < c.req;
	}
};


void main2() {
	City stars2[MAX_N];
	City stars1[MAX_N];
	bool used[MAX_N];
	bool bad[MAX_N];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		used[i] = bad[i] = false;
		stars2[i].id = stars1[i].id = i;
		scanf("%d %d", &stars1[i].req, &stars2[i].req);
	}
	int best = INT_MAX;
	for(int shuffle = 0; shuffle < 20000; shuffle++) {
		for (int i = 0; i < n; i++) used[i] = bad[i] = false;
		random_shuffle(stars2, stars2+n);
		random_shuffle(stars1, stars1+n);
		stable_sort(stars2, stars2+n);
		stable_sort(stars1, stars1+n);
		int nstars = 0;
		int ans = 0;
		int p1=0, p2=0;
		int lastp1 = 0, lastp2 = 0;
		while (nstars < 2*n) {
			while (p2 < n && stars2[p2].req <= nstars) {
				ans++;
				bad[stars2[p2].id] = true;
				if (used[stars2[p2].id]) nstars++;
				else nstars += 2;
				p2++;
			}
			while (p1 < n && bad[stars1[p1].id]) p1++;
			if (p1 < n && stars1[p1].req <= nstars) {
				ans++;
				nstars++;
				used[stars1[p1].id] = true;
				p1++;
			}
			if(lastp1 == p1 && lastp2 == p2) {
				printf("Too Bad\n");
				return;
			}
			lastp1 = p1;
			lastp2 = p2;
		}
		if (best > ans) best = ans;
	}
	printf("%d\n", best);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		main2();
	}
}
