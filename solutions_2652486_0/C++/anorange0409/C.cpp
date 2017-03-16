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

int a[100], c[100], ans[100], p[100];
int R,N,K,M;
bool FIND;

void tdo(int k){
    for (int i = 1; i <= K; i++)
        if (c[i] == k) c[i] = -1;
}

void check(){
    for (int i = 1; i <= K; i++)
        c[i] = p[i];
    tdo(a[1]);tdo(a[2]);tdo(a[3]);
    tdo(a[1]*a[2]);tdo(a[2]*a[3]);tdo(a[3]*a[1]);
    tdo(a[1]*a[2]*a[3]);
    tdo(1);
    for (int i = 1; i <= K; i++)
        if (c[i] != -1) return;
    FIND = true;
    memcpy(ans, a, sizeof(ans));
}

void dfs(int t){
    if (FIND) return;
    if (t > N) check();
    else{
        for (int i = 2; i <= M; i++){
            a[t] = i;
            dfs(t + 1);
        }
    }
}


int main(){
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("C-small-1-attempt0.out","w",stdout);
    int testcase;
    cin >> testcase;
    printf("Case #%d:\n", 1);
    cin >> R >> N >> M >> K;
    for (int t = 1; t <= R; t++){
        for (int i = 1; i <= K; i++)
            cin >> p[i];
        FIND = false;
        ans[1] = ans[2] = ans[3] = 2;
        dfs(1);
        for (int i = 1; i <= N; i++)
            cout << ans[i];
        cout << endl;
    }
}
