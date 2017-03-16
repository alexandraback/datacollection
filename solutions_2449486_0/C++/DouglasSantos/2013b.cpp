#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
using namespace std;

typedef long long int int64;

#define EPS 10e-9
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

int n, m;
int v[120][120];
int c[120];
bool used[120][120];

bool verifica(int x) {
	REP(i, n) {
		bool achou = true;
		bool first = false;
		REP(j, m) {
			if (used[i][j]) continue;
			first = true;
			if (v[i][j] != x) {
				achou = false;
				break;
			}
		}
		if (achou && first) {
			REP(j, m) {
				if (!used[i][j]) c[x]--;
				used[i][j] = true;
			}
			return true;
		}
	}
	
	REP(j, m) {
		bool achou = true;
		bool first = false;
		REP(i, n) {
			if (used[i][j]) continue;
			first = true;
			if (v[i][j] != x) {
				achou = false;
				break;
			}
		}
		if (achou && first) {
			REP(i, n) {
				if (!used[i][j]) c[x]--;
				used[i][j] = true;
			}
			return true;
		}
	}
	
	return false;
}

int main()
{	
	int t;
	scanf("%d", &t);
	REP(k, t) {
		scanf("%d %d", &n, &m);
		memset(c, 0, sizeof(c));
		memset(used, false, sizeof(used));
		REP(i, n) {
			REP(j, m) {
				scanf("%d", &v[i][j]);
				c[v[i][j]]++;
			}
		}
		bool erro = false;
		int i = 0;
		while (1) {
			if (i == 101) break;
			if (c[i] == 0) {
				i++;
				continue;
			}
			if (!verifica(i)) {
				erro = true;
				break;
			}
		}	
		printf("Case #%d: ", k+1);
		if (!erro)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}