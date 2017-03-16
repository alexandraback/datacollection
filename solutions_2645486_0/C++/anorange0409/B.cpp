/*
 *		Problem		:
 *		Author		: Yicheng Huang from Dept.Computer Science & Technology, PKU
 *		Date		: 2013-04-27
 *		Algorithm	:
 *
 */

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <ctime>
#include <queue>

#define PB push_back
#define MP make_pair
#define two(X) (1<<X)
#define ME(a) memset(a, 0, sizeof(a))
#define MCP(a, b) memcpy(a, b, sizeof(b))
#define eps 1e-8
#define sqr(x) ((x) * (x))

typedef unsigned long long LL;

using namespace std;

int E, R , N, v[100000], ans;

void dfs(int t, int e, int sum){
    if (t > N){
        if (sum > ans) ans = sum;
        return;
    }
    for (int i = 0; i <= e; i++)
        dfs(t + 1, min(E, e - i + R), sum + i * v[t]);
}

int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int testcase;
    cin >> testcase;
    for (int  t = 1; t <= testcase; t++){
        printf("Case #%d: ", t);
        cin >> E >> R >> N;
        for (int i = 1; i <= N; i++)
            cin >> v[i];
        ans = 0;
        dfs(1, E, 0);
        cout << ans << endl;
    }
}
