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

int main(){
    int T;
    scanf("%d", &T);
    vector <int> backlink;
    vector <char> pattern, keys;
    For(cases, T) {
        int k, l, s;
        scanf("%d %d %d", &k, &l, &s);
        pattern.resize(l+1);
        backlink.resize(l + 1);
        keys.resize(k);
        vector<double> states(l +3, 0.0), newstates(l + 3, 0.0);
        For(i, k) scanf(" %c", &keys[i]);
        For(i, l) scanf(" %c", &pattern[i]);

        bool isthere = false;
        For(i, l) {
            isthere = false;
            For(j, k) {
                if (keys [j] == pattern [i]) {
                    isthere = true;
                    break;
                }
            }
            if (!isthere) break;
        }

        if (!isthere) {
            printf("Case #%d: 0.0\n", cases + 1);
            continue;
        }
        pattern[l] = '$';
        backlink [0] = -1;
        for (int i = 1; i <= l; i++) {
            backlink [i] = backlink [i - 1];
            while (backlink [i] >= 0 && pattern [i - 1] != pattern [backlink [i]]) backlink [i] = backlink [backlink [i]];
            backlink [i] ++;
        }
        int state = 0, minimum = 0;
        double probstate;
        For(i, s) {
            state ++;
            if (state == l) {
                minimum ++;
                state = backlink [state];
            }
        }
        
        cerr << minimum << endl;
        double expected = 0.0;
        states [0] = 1.0;
        For(i2, s) {
            For(i, l) {
                For(j, k) {
                    state = i;
                    probstate = states [i] / (double) k;
                    while (state >= 0 && keys [j] != pattern [state]) state = backlink [state];
                    state ++;
                    if (state == l) {
                        expected += probstate;
                        state = backlink [state];
                    }
                    newstates [state] += probstate;
                }

            }
            For(i, l+3) {
                states [i] = newstates [i];
                cerr << states [i] << endl;
                newstates [i] = 0.0;
            }
        }

        printf("Case #%d: %.6lf\n", cases + 1, (double) minimum - expected);
        
    }

}
