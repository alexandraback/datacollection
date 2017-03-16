#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

#define pb push_back

using namespace std;

const int ADD = 200;

struct el {
    int d, w, e, s;

    el() {}
    el(int _d, int _w, int _e, int _s): d(_d), w(_w), e(_e), s(_s) {}
};

int N;
int h[512];
vector< el > vec;
vector< el > rep;

void read() {
    int d, n, w, e, s, deltaD, deltaP, deltaS;

    memset(h, 0, sizeof(h));
    vec.clear();
    rep.clear();

    scanf("%d", &N);
    for(int i = 0; i < N; i ++) {
        scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &deltaD, &deltaP, &deltaS);
        for(int j = 0; j < n; j ++)
            vec.pb(el(d + j * deltaD, w + j * deltaP, e + j * deltaP, s + j * deltaS));
    }
}

bool cmp(el a, el b) {
    return a.d < b.d;
}

void solve() {
    for(int i = 0; i < vec.size(); i ++)
        vec[i].w += ADD, vec[i].e += ADD;

    sort(vec.begin(), vec.end(), cmp);

    int ans = 0;
    for(int i = 0; i < vec.size(); i ++) {
        bool fl = false;
        for(int j = vec[i].w; j < vec[i].e; j ++)
            if(h[j] < vec[i].s) {
                fl = true;
                break;
            }
        if(fl) {
            ans ++;
            rep.pb(vec[i]);
        }

        if(i != vec.size() - 1 && vec[i].d != vec[i + 1].d) {
            for(int j = 0; j < rep.size(); j ++)
                for(int k = rep[j].w; k < rep[j].e; k ++)
                    h[k] = max(h[k], rep[j].s);
            rep.clear();
        }
    }

    cout << ans << endl;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i ++) {
        printf("Case #%d: ", i);
        read();
        solve();
    }

    return 0;
}
