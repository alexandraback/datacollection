#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long int64;
typedef long double ldouble;

#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)

#define PROBLEM "B"

struct Level {
	int x, y, comp;
};

const int MAXN = 1024;
Level a[MAXN];

bool cmpLevel(Level a, Level b) {
	if (a.y != b.y) return a.y > b.y;
	return a.x < b.x;
}

int main() {
	freopen(PROBLEM ".in", "rt", stdin);
	freopen(PROBLEM ".out", "wt", stdout);

	int T;
	scanf("%d\n", &T);

	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a[i].x, &a[i].y);
			a[i].comp = 0;
		}

		stable_sort(a, a+n, cmpLevel);

		int xod = 0, stars = 0;
		bool bad = false;
        while (stars < 2*n) {
        	int found;

        	found = -1;
        	for (int i = 0; i < n; i++) {
        		if (a[i].comp == 1 && a[i].y <= stars) {
        			found = i;
        			break;
        		}
        	}

        	if (found != -1) {
        		xod++;
        		stars++;
        		a[found].comp = 2;
        		continue;
        	}

        	found = -1;
        	for (int i = 0; i < n; i++) {
        		if (a[i].comp == 0 && a[i].y <= stars) {
        			found = i;
        			break;
        		}
        	}

        	if (found != -1) {
        		xod++;
        		stars+=2;
                a[found].comp = 2;
                continue;
        	}

        	found = -1;
        	for (int i = 0; i < n; i++) {
        		if (a[i].comp == 0 && a[i].x <= stars) {
        			found = i;
        			break;
        		}
        	}

        	if (found != -1) {
        		xod++;
        		stars++;
                a[found].comp = 1;
                continue;
        	}

        	bad = true;
        	break;
        }

        if (bad) printf("Too Bad");
        else printf("%d", xod);
		printf("\n");
	}

	return 0;
}
