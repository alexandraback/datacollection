#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <bitset>
#include <climits>
#include <stack>
#include <cctype>
#include <sstream>
#define MAX 1000ULL
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int r, t;

bool comp(int x) {
    return (x+1)*(ll)(2*r + 2*x + 1) <= t;
}

int main()	{
    int T, i, ans;

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.txt", "w", stdout);

	scanf("%d", &T);
	for(i=1; i<=T; i++)  {
        scanf("%d %d", &r, &t);
        for(ans = 0; ans < MAX && comp(ans); ans++);
        printf("Case #%d: %d\n", i, ans);
	}

	return 0;
}
