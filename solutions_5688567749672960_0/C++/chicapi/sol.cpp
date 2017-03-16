#include <assert.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef unsigned int UINT;
typedef long long unsigned int ULL;
typedef long long int LL;

const int MAXN = 1000010;
const int MOD = 1000000007;

bool visited[MAXN];

ULL bfs(ULL N)
{
    queue<ULL> q;
    q.push(1);
    ULL count = 0;
    ULL sz = 1;
    memset(visited, 0, sizeof visited);
    visited[1] = true;
    while (!q.empty()) {
        count++;
        for (ULL i = 0; i < sz; i++) {
            ULL num = q.front();
            //cout << "? " << num << endl;
            q.pop();
            if (num == N) return count;
            if (!visited[num+1]) {
                q.push(num+1);
                visited[num+1] = true;
                //cout << "+ " << num+1 << endl;
            }
            char buf[20];
            sprintf(buf, "%llu", num);
                //cout << "buf " << buf << endl;
            ULL mum = 0;
            for (int j = strlen(buf) - 1; j >= 0 ; j--) {
                //cout << "mum " << mum*10 << " + " << buf[j] << "/" << j << endl;
                mum = mum*10 + (buf[j] - '0');
                //cout << "mum " << mum << endl;
            }
            if (!visited[mum] && mum > num && mum <= N) {
                q.push(mum);
                visited[mum] = true;
                //cout << "+ " << mum << endl;
            }
        }
        sz = q.size();
        //cout << sz << endl;
    }
    return count;
}

int main ()
{
    int TT;
    scanf("%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        ULL N;
        scanf("%llu", &N);
        ULL sol = bfs(N);
        printf("Case #%d: %llu\n", tt, sol);
    }
    return 0;
}
