//
// DeceitfulWar.cpp
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

#define MAXN 1005

double A[MAXN], B[MAXN];
int N;
bool used[MAXN];

void solve() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lf", &A[i]);
    for (int i = 0; i < N; i++) scanf("%lf", &B[i]);
    sort(A, A + N);
    sort(B, B + N);
    fill(used, used + N, false);
    int ans2 = 0;
    for (int i = N - 1; i >= 0; i--) {
	bool found = false;
	int first = -1;
	for (int j = 0; j < N; j++) {
	    if (used[j] == false && first == -1) {
		first = j;
	    }
	    if (used[j] == false && B[j] > A[i]) {
		found = true;
		used[j] = true;
		break;
	    }
	}
	if (!found) {
	    ans2++;
	    used[first] = true;
	}
    }

    int ans1 = 0;
    int left = 0, right = N - 1;
    for (int i = 0; i < N; i++) {
	if (A[i] > B[left]) {
	    ans1++;
	    left++;
	} else {
	    right--;
	}
    }
    printf("%d %d\n", ans1, ans2);
}


int main() {
    int test;
    scanf("%d", &test);
    for (int tt = 0; tt < test; tt++) {
	printf("Case #%d: ", tt + 1);
	solve();
    }   
    return 0;
}
