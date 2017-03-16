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


int main()
{
	freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    //freopen("a.in","rt",stdin);
    //freopen("a.out","wt",stdout);
	
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		int R, C, W;
		scanf("%d %d %d", &R, &C, &W);
		int res = 0;
		if(W == 1) {
			res = R * C;
		}
		else if(W == C) {
			res = R + C - 1;
		}
		else {
			int cnt = 0;
			for(int i = W; i <= C; i += W) cnt++;
			if(C % W == 0) cnt--;
			res = R * cnt + W;
		}
		printf("Case #%d: %d\n", t, res);
	}

    return 0;
}