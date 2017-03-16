#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 500;
const int OFF = MAX / 2 + 5;


struct event {
	// left right
	int l, r;
	// height
	int h;
	// day
	int d;
};

int wallNew[MAX];
int wallOld[MAX];

int n;
event events[10 * 10 + 10];
int numEvents;

bool cmp(event a, event b) {
	return a.d < b.d;
}

void proc() {
	scanf("%d", &n);
	numEvents = 0;
	for (int i = 0; i < n; i++) {
		int d, ni, w, e, s, di, pi, si;
		scanf("%d%d%d%d%d%d%d%d", &d, &ni, &w, &e, &s, &di, &pi, &si);
		for (int j = 0; j < ni; j++) {
			events[numEvents].d = d + j * di;
			events[numEvents].h = s + j * si;
			events[numEvents].l = w + j * pi + OFF;
			events[numEvents].r = e + j * pi + OFF;
			numEvents++;
		}
	}

	sort(events, events + numEvents, cmp);

	int ans = 0;

	for (int i = 0; i < MAX; i++) {
		wallNew[i] = wallOld[i] = 0;
	}

	for (int i = 0; i < numEvents; i++) {
		if (i != 0 && events[i].d != events[i - 1].d) {
//			printf("Making new wall\n");
			for (int j = 0; j < MAX; j++) {
				wallOld[j] = wallNew[j];
//				printf("%d ", wallNew[j]);
			}
//			printf("\n");
		}
		bool success = false;
		for (int j = events[i].l; j < events[i].r; j++) {
			if (events[i].h > wallOld[j]) {
				success = true;
				wallNew[j] = max(wallNew[j], events[i].h);
			}
		}
		if (success) {
			ans++;
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		proc();
	}

	return 0;
}
