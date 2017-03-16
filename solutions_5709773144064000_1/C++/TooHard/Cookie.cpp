//
// Cookie.cpp
//
// Siwakorn Srisakaokul - ping128
// Written on Friday, 11 April 2014.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <string.h>

#include <assert.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

void solve() {
    double C, F, X;
    cin >> C >> F >> X;
    double nowRate = 2.0;
    double bestTime = X / nowRate;
    double accTime = 0.0;
    while (1) {
	double timeUsedToBuyFarm = C / nowRate;
	double newTime = accTime + timeUsedToBuyFarm + (X / (nowRate + F));
	if (newTime < bestTime - 0.000000001) {
	    bestTime = newTime;
	    accTime += timeUsedToBuyFarm;
	    nowRate += F;
	} else {
	    break;
	}
    }
    printf("%.7lf\n", bestTime);
}

int main() {
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++) {
	printf("Case #%d: ", i + 1);
	solve();
    }
    return 0;
}
