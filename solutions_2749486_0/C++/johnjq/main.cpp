#include <iostream>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct State {
    int acc;
    int x, y;
    bool operator<(const State rhs) const {
        if (acc == rhs.acc) {
            if (x == rhs.x) {
                return y < rhs.y;
            }
            return x < rhs.x;
        }
        return acc < rhs.acc;
    }
};

void run() {
    int x, y;
    cin>>x>>y;
    string ans;

    string sx = x > 0 ? "WE" : "EW";
    string sy = y > 0 ? "SN" : "NS";
    x = abs(x);
    y = abs(y);
    for (int i = 0; i < x; ++i) {
        ans += sx;
    }
    for (int i = 0; i < y; ++i) {
        ans += sy;
    }
    cout << " " << ans <<endl;
}

int main()
{
    #if 1
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w+", stdout);
    #endif

	int testcases;
	scanf("%d", &testcases);
	for (int testcase = 1; testcase <= testcases; ++testcase)
	{
	    printf("Case #%d:", testcase);
		run();
	}
	return 0;
}
