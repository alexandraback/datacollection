#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <unordered_set>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV

int F[25];

int main() {
	int T, Q, R, C, W;
	scanf("%d", &T);
	for (Q=1;Q<=T;Q++) {
		scanf("%d%d%d", &R, &C, &W);
		int ans=0;
		if (C%W==0)
			ans=C/W+W-1;
		else {
			ans=C/W+W;
		}
		printf("Case #%d: %d\n", Q, R*ans);
	}
}





