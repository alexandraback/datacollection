#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

const int INF (1<<29);

bool match(int x, char *Y, int n) {
	for (int i = 0; i < n; i++) {
		if (!(Y[n-1-i] == '?' || x % 10 == Y[n-1-i]-'0'))
			return false;
		x /= 10;
	}
	return true;
}

pair<string, string> solve(char *C, char *J) {
	int n = strlen(C);
	int m = 1;
	for (int i = 0; i < n; i++)
		m *= 10;
	int mind = INF;
	int minc = INF;
	int minj = INF;
	for (int i = 0; i < m; i++) {
		if (match(i, C, n)) {
			for (int j = 0; j < m; j++) {
				if (match(j, J, n)) {
					int d = abs(i-j);
					if (d == mind) {
						if (i == minc) {
							minj = min(minj, j);
						} else if (i < minc) {
							minc = i;
							minj = j;
						}
					} else if (d < mind) {
						mind = d;
						minc = i;
						minj = j;
					}
				}
			}
		}
	}
	char cc[100], jj[100];
	sprintf(cc, "%0*d", n, minc);
	sprintf(jj, "%0*d", n, minj);
	return make_pair(string(cc), string(jj));
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i <T; i++) {
		char C[20], J[20];
		scanf("%s %s", C, J);
		pair<string, string> ans = solve(C, J);
		printf("Case #%d: %s %s\n", i+1, ans.first.c_str(), ans.second.c_str());
	}
}
