#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define For(i, n) for (int i = 0; i < (int) n; ++i)
#define SIZE(x) ((int) (x).size())
#define mp(a, b) make_pair(a, b)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#ifndef DG
#define DG 0
#endif
#define LOG(...) (DG ? fprintf(stderr, __VA_ARGS__) : 0)

vector <int> bff;
vector <int> step;
vector <int> maxbefore;
int maxcycle;

void dfs(int v, int s) {
    if (step [v] != -1) {
        maxcycle = max(maxcycle, s - step [v]);
        maxbefore [v] = max(step [v], maxbefore [v]);
    }
    else {
        step [v] = s;
        dfs(bff [v], s+1);
    }
}

int main(){
    int t;
    cin >> t;
    For(cases, t) {
        int n;
        maxcycle = -1;
        cin >> n;
        vector <bool> doublecycle(n, false);
        bff.resize(n);
        step.resize(n, -1);
        maxbefore.resize(n, 0);
        For(i, n) {
            cin >> bff [i];
            bff [i] --;
        }
        For(i, n) if (bff [bff [i]] == i) doublecycle [i] = true;
        For(i, n) {
            step.clear();
            step.resize(n, -1);
            dfs(i, 0);
        }
        int doublecyclers = 0, result = 0;
        vector <bool> counted(n, false);
        For(i, n) if (doublecycle [i]) doublecyclers ++;
/*        For(i, n) {
            if (doublecycle [i]) {
                int best = 0;
                For(j, n) {
                    if (j == i || j == bff [i] || !doublecycle [j]) continue;
                    best = max(best, maxbefore [j]);
                }
                result = max(result, doublecyclers + maxbefore [i] + best);
                cout << result << endl;
            }
        }*/
        result = doublecyclers;
        For(i, n) {
            if (doublecycle [i] && !counted[i]) {
                result += maxbefore [i] + maxbefore [bff [i]];
                counted [i] = true;
                counted [bff [i]] = true;
            }
        }
        printf("Case #%d: %d\n", cases + 1, max(result, maxcycle));
        bff.clear();
        step.clear();
        maxbefore.clear();
    }

}
