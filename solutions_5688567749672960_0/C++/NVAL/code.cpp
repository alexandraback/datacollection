#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <time.h>
using namespace std;
#pragma comment(linker, "/STACK:200000000")

#define mp make_pair
#define pb push_back 
#define ll long long
#define sz(x) (int)(x).size()

int dp[1000100];

int rev(int x) {
	int val = x;
	int res = 0;
	while(val > 0) {
		res *= 10;
		res += val % 10;
		val /= 10;
	}

	return res;
}

int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    //freopen("a.in","rt",stdin);
    //freopen("a.out","wt",stdout);
	
	queue<int> q;
	q.push(1);
	dp[1] = 1;
	while(!q.empty()) {
		int s = q.front();
		q.pop();
		if(s + 1 <= 1000000 && dp[s+1] == 0) {
			dp[s+1] = dp[s] + 1;
			q.push(s + 1);
		}
		int r = rev(s);
		if(r <= 1000000 && dp[r] == 0) {
			dp[r] = dp[s] + 1;
			q.push(r);
		}
	}

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);
		printf("Case #%d: %d\n", t, dp[N]);
	}

    return 0;
}