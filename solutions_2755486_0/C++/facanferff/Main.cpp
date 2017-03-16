#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
// Uncomment for libgmp
/*#include "gmpxx.h"
#define big mpz_class*/

using namespace std;

struct Tribe {
	int id;
	int d;
	int n;
	int w, e;
	int s;
	int delta_d;
	int delta_p;
	int delta_s;
};

struct Attack {
	int id;
	int day;
	int w;
	int e;
	int s;
};

struct Change {
	int w;
	int e;
	int h;
};

bool cmp(const Attack &a, const Attack &b) {
	if (a.day != b.day)
		return a.day < b.day;
	return a.id < b.id;
}

int n;
 
int main()
{
    int t;
    scanf("%d", &t);
    for (int c = 1; c <= t; c++) {
    	fprintf(stderr, "Case #%d of %d...\n", c, t);
    	scanf("%d", &n);
    	Tribe tribes[n];
    	vector<Attack> attacks;
    	for (int i = 0; i < n; i++) {
    		Tribe t;
    		t.id = i;
    		scanf("%d %d %d %d %d %d %d %d", &t.d, &t.n, &t.w, &t.e, &t.s, &t.delta_d, &t.delta_p, &t.delta_s);
    		tribes[i] = t;

    		int d = t.d;
    		int w = t.w;
    		int e = t.e;
    		int s = t.s;
    		for (int j = 0; j < t.n; j++) {
    			Attack a;
    			a.day = t.d + j * t.delta_d;
    			a.w = t.w + j * t.delta_p;
    			a.e = t.e + j * t.delta_p;
    			a.s = t.s + j * t.delta_s;
    			a.id = i;
    			attacks.push_back(a);
    		}
    	}

    	sort(attacks.begin(), attacks.end(), cmp);

    	int tot = 0;
    	map<int, int> height;
    	map<pair<int, int>, int> sheight;

    	map<int, int> height0;
    	int w0, e0, s0;

    	vector<Change> changes;

    	for (int i = 0; i < attacks.size(); i++) {
    		Attack a = attacks[i];
    		bool found = false;
    		//printf("%d: %d %d %d %d\n", a.id + 1, a.day, a.w, a.e, a.s);

    		if (i >= 0 && a.day != attacks[i - 1].day) {
    			for (int j = 0; j < changes.size(); j++) {
    				Change c = changes[j];
    				for (int k = c.w; k <= c.e; k++) {
    					if (height[k] < c.h) {
    						height[k] = c.h;
    					}

    					if (k + 1 <= c.e && sheight[make_pair(k, k + 1)] < c.h) {
    						sheight[make_pair(k, k + 1)] = c.h;
    					}
    				}
    			}
    			changes.clear();
    		}

    		for (int j = a.w; j <= a.e; j++) {
    			if ((height[j] < a.s || (j + 1 <= a.e && sheight[make_pair(j, j + 1)] < a.s)) && !found) {
    				tot++;
    				found = true;

    				Change c;
    				c.w = a.w;
    				c.e = a.e;
    				c.h = a.s;
    				changes.push_back(c);
    			}
    		}
    		/*if (found)
    			printf("succesfull!\n");*/
    	}

    	printf("Case #%d: %d\n", c, tot);
    }
    return 0;
}
