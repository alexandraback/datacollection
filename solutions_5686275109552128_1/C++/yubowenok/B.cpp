#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 1005

int N;
int x[MAXN];
int main(){
	int cs;
	cin >> cs;
	REP(csn, 1, cs + 1){
		printf("Case #%d: ", csn);
		cin >> N;
		int ans = 0;
		REP(i, 0, N) {
			scanf("%d", x + i);
			ans = max(ans, x[i]);
		}
		REP(h, 1, 1001){
			int sol = h;
			REP(i, 0, N){
				if (x[i] > h)
					sol += (x[i] - 1) / h;
			}
			ans = min(ans, sol);
		}
		printf("%d\n", ans);
	}
	return 0;
}