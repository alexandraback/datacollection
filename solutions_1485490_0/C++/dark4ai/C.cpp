#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;

int n, m;
vector<pair<int, llong> > boxes;
vector<pair<int, llong> > toys;
vector<int> indexs;
vector<llong> sums, sums2;
set<int> types;
llong answer = 0, cur = 0;

void rec(int b, int t) {
    if(b == boxes.size() || t == toys.size()) {
        answer = max(answer, cur);
        return;
    }
    if(boxes[b].first == toys[t].first) {
        if(boxes[b].second > toys[t].second) {
            boxes[b].second -= toys[t].second;
            cur += toys[t].second;
            rec(b, t + 1);
            cur -= toys[t].second;
            boxes[b].second += toys[t].second;
        } else {
            toys[t].second -= boxes[b].second;
            cur += boxes[b].second;
            rec(b + 1, t);
            cur -= boxes[b].second;
            toys[t].second += boxes[b].second;
        }
    }
    rec(b + 1, t);
    rec(b, t + 1);
}

void rec2(int d, int start) {
    if(d == n) {
        int lst = 0;
        llong cans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = lst; j < indexs[i]; j++) {
                if(boxes[i].first == toys[j].first) {
                    llong add = min(boxes[i].second, toys[j].second);
                    boxes[i].second -= add;
                    toys[j].second -= add;
                    sums[i] += add;
                    sums2[j] += add;
                    cans += add;
                }
            }
            if(indexs[i] > 0 && toys[indexs[i] - 1].second > 0) {
                lst = indexs[i] - 1;
            } else {
                lst = indexs[i];
            }
        }
        answer = max(answer, cans);
        for(int i = 0; i < boxes.size(); i++) {
            boxes[i].second += sums[i];
            sums[i] = 0;
        }
        for(int j = 0; j < toys.size(); j++) {
            toys[j].second += sums2[j];
            sums2[j] = 0;
        }
        return;
    }
    for(int i = start; i <= toys.size(); i++) {
        indexs[d] = i;
        rec2(d + 1, i);
    }
}

void solve() {
    cin >> n >> m;
    boxes.clear();
    toys.clear();
    types.clear();    
    indexs.resize(n, 0);
    sums.resize(n, 0);
    sums2.resize(m, 0);
    answer = 0;
    cur = 0;    
    for(int i = 0; i < n; i++) {
        int t;
        llong count;
        cin >> count >> t;
        boxes.push_back(make_pair(t, count));
        types.insert(t);
    }
    for(int i = 0; i < m; i++) {
        int t;
        llong count;
        cin >> count >> t;
//        if(types.count(t)) {
        toys.push_back(make_pair(t, count));
//        }
    }    
//    cerr << boxes.size() << " " << toys.size() << endl;
//    rec(0, 0);
    rec2(0, 0);
    cout << " " << answer << endl;
}

int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":";
        solve();
    }
    return 0;
}
