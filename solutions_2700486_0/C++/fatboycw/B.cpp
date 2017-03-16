/*
 * Author: fatboy_cw
 * Created Time:  2013/5/5 1:07:58
 * File Name: B.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

set< pair<int, int> > st;
vector< pair<int, int> > vec;
int T, N, X, Y, ca;
double ans;

void output(double x) {
    printf("Case #%d: ", ++ca);
    printf("%.7lf\n", x);
}

int findMaxY() {
    int MAXY = 0;
    for(set< pair<int, int> >::iterator it = st.begin(); it != st.end(); it++) {
        if(it->first == 0) {
            MAXY = max(MAXY, it->second);
        }
    }
    return MAXY;
}

bool exist(int x, int y) {
    return st.count(make_pair(x, y));
}

pair<int, int> slideLeft(int x, int y) {
    while(1) {
        if(exist(x - 1, y - 1) || y == 0) {
            return make_pair(x, y);
        }
        x--, y--;
    }
}

pair<int, int> slideRight(int x, int y) {
    while(1) {
        if(exist(x + 1, y - 1) || y == 0) {
            return make_pair(x, y);
        }
        x++, y--;
    }
}

void dfs(int ind, double prob) {
    if(vec.back().first == X && vec.back().second == Y) {
        ans += prob;
    }
    if(ind == N) {
        return;
    }
    int MAXY = findMaxY();
    int x = 0, y = MAXY + 2;
    if(!exist(x - 1, y - 1) && exist(x + 1, y - 1)) {
        pair<int, int> p = slideLeft(x, y);
        vec.push_back(p);
        st.insert(p);
        dfs(ind + 1, prob);
        vec.pop_back();
        st.erase(p);
    }
    else if(exist(x - 1, y - 1) && !exist(x + 1, y - 1)) {
        pair<int, int> p = slideRight(x, y);
        vec.push_back(p);
        st.insert(p);
        dfs(ind + 1, prob);
        vec.pop_back();
        st.erase(p);
    }
    else if(!exist(x - 1, y - 1) && !exist(x + 1, y - 1)) {
        pair<int, int> p;
        p = slideLeft(x, y);
        vec.push_back(p);
        st.insert(p);
        dfs(ind + 1, prob * 0.5);
        vec.pop_back();
        st.erase(p);
        
        p = slideRight(x, y);
        vec.push_back(p);
        st.insert(p);
        dfs(ind + 1, prob * 0.5);
        vec.pop_back();
        st.erase(p);
    }
    else {
        pair<int, int> p = make_pair(x, y);
        vec.push_back(p);
        st.insert(p);
        dfs(ind + 1, prob);
        vec.pop_back();
        st.erase(p);
    }
}

int main() {
    freopen("B.out", "w", stdout);
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &N, &X, &Y);
        if(N == 1) {
            if(X == 0 && Y == 0) {
                output(1.0);
            }
            else {
                output(0.0);
            }
            continue;
        }
        st.clear();
        vec.clear();
        ans = 0.0;
        vec.push_back(make_pair(0, 0));
        st.insert(make_pair(0, 0));
        dfs(1, 1.0);
        output(ans);
    }
    return 0;
}

