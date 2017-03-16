// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 20;
const int INF = 0x3f3f3f3f;
const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int n;

map<int,int> key_count;

int opened_by[M + 5];
VVI keys(M);

int prev[(1<<M) + 5];

map<int, int> compute_state(int mask) {
    map<int, int> state = key_count;
    for(int i=0;i<n;++i)
        if(mask&1<<i) {
            state[opened_by[i]]--;
            for(int j=0;j<SZ(keys[i]);++j)
                state[keys[i][j]]++;
        }
    return state;
}

void doit(int mask, int prev_node) {
    if (prev[mask] != -1) {
        return;
    }
    prev[mask] = prev_node;

    int bit_count = __builtin_popcount(mask);
    if(bit_count == n) return;

    map<int, int> state = compute_state(mask);

    for(int i=0;i<n;++i) {
        if((mask&1<<i) == 0 && state[opened_by[i]] > 0) {
            int new_mask = mask | (1<<i);
            doit(new_mask, i);
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int t=1; t<=tc;++t) {

        for(int i=0;i<M;++i) keys[i].clear();
        key_count.clear();

        int k;
        scanf("%d %d", &k, &n);
        while (k--) {
            int x;
            scanf("%d", &x);
            key_count[x]++;
        }

        for(int i=0;i<n;++i) {
            int ck;
            scanf("%d", &ck);
            opened_by[i] = ck;

            int ki;
            scanf("%d", &ki);
            VI curr_keys;
            while(ki--) {
                int x;
                scanf("%d", &x);
                curr_keys.push_back(x);
            }
            keys[i] = curr_keys;
        }

        SET(prev, -1);

        doit(0, -42);

        printf("Case #%d:", t);

        int curr_mask = (1<<n) -1;
        if(prev[curr_mask] == -1)
            puts(" IMPOSSIBLE");
        else {
            VI result;
            int c = prev[curr_mask];
            while (c != -42) {
                result.push_back(c);
                int prev_mask = curr_mask ^ (1<<c);
                curr_mask = prev_mask;
                c = prev[curr_mask];
            }
            reverse(ALL(result));
            for(int i=0;i<SZ(result);++i) {
                printf(" %d", result[i] +1);
            }
            puts("");
        }

    }
    return 0;
}

