#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define mp make_pair
#define st first
#define nd second
#define FOR(i,n) for(int i=0;i<(n);i++)
#define FORO(i,n) for(int i=1;i<=(n);i++)
#define FORS(i,a,n) for(int i=(a);i<(n);i++)
#define FORB(i,a,n) for(int i=(a);i>=(n);i--)
#define FORE(i,v) for(typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define INRANGE(a,b,c,d) ((a)>=0&&(b)>=0&&(a)<(c)&&(b)<(d))
#define pf printf
typedef long long ll;
using namespace std;

int n;
int s[50];
int nways[2000001];

void rec(int i, int sm) {
	if (i == n)
		nways[sm]++;
	else {
		rec(i+1, sm);
		rec(i+1, sm+s[i]);
	}
}

int pres = 0;
int lookfor;

vector<int> sta;

void rec2(int i, int sm) {
	if (i == n) {
		if (sm == lookfor && pres < 2) {
			pres++;
			printf("%d", sta[0]);
			FORS(j, 1, sta.size())
				printf(" %d", sta[j]);
			printf("\n");
		}
	}
	else {
		rec2(i+1, sm);
		sta.push_back(s[i]);
		rec2(i+1, sm+s[i]);
		sta.pop_back();
	}
}

int main() {
	//freopen(".in", "r", stdin); freopen(".out", "w", stdout);
	int tc;
	scanf("%d", &tc);
	FOR(i, tc) {
		printf("Case #%d:\n", i+1);
		scanf("%d", &n);
		FOR(j, n)
			scanf("%d", s+j);
		fill(nways, nways+2000001, 0);
		rec(0, 0);
		int found = -1;
		FORS(j, 1, 2000001) {
			if (nways[j] > 1) {
				found = j;
				break;
			}
		}
		if (found == -1)
			printf("Impossible\n");
		else {
			pres = 0;
			lookfor = found;
			rec2(0, 0);
		}
	}
}


