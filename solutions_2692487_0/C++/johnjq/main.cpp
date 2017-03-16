#include <iostream>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> motes;
int a, n;

int divide(int a, int b) {
    if ((a % b) == 0)
        return a / b;
    else
        return 1 + (a / b);
}

int solve(int a, int endv) {
    int result = 0;
    int sum = a;
    for (int i = 0; i < endv; ++i) {
        int x = motes[i];

        if (x < sum) {
            sum += x;
        } else {
            if (sum <= 1) //todo: probably comment
                return 99999999;

            while (sum <= x) {
                sum += (sum-1);
                ++result;
            }
            sum += x;
        }
    }
    return (n-endv) + result;
}

void run() {
    motes.clear();
    cin>>a>>n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        motes.push_back(x);
    }
    sort(motes.begin(), motes.end());

    int best = solve(a, n);
    for (int i = 0; i < n; ++i) {
        int val = solve(a, i);
        if (val < best)
            best = val;
    }
    printf(" %d\n", best);
}

int main()
{
    #if 1
    freopen("input2.txt", "r", stdin);
    freopen("A-small.out", "w+", stdout);
    #endif // ONLINE_JUDGE

	int testcases;
	scanf("%d", &testcases);
	for (int testcase = 1; testcase <= testcases; ++testcase)
	{
	    printf("Case #%d:", testcase);
		run();
	}
	return 0;
}
