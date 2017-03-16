#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define rtrav(it, v) for(typeof((v).rbegin()) it = (v).rbegin(); it != (v).rend(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
		char buff[2000];
		int S;
		scanf("%d %s", &S, buff);
		int invites = 0, tot = 0;
		for (int s = 0; s<=S; ++s) {
			if (tot < s) {
				invites += s-tot;
				tot = s;
			}
			tot += buff[s]-'0';
		}

		printf("Case #%d: %d\n", t+1, invites);
	}
	return 0;
}