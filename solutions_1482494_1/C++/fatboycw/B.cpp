#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

vector< pair<int, int> > vec;
vector< pair<bool, bool> > vis;
int t, n, ca;


int main() {
    freopen("B.out", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        vec.clear();
        vis.clear();
        for(int i = 0; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            vec.push_back(make_pair(u, v));
            vis.push_back(make_pair(false, false));
        }
        int ans = 0, star = 0;
        while(1) {
            bool change = false;
            for(int i = 0; i < n; i++) {
                if(vis[i].first || vis[i].second) continue;
                if(star >= vec[i].second) {
                    star += 2;
                    ans++;
                    vis[i].first = vis[i].second = true;
                    change = true;
                    break;
                }
            }
            if(change) continue;
            for(int i = 0; i < n; i++) {
                if(vis[i].first && !vis[i].second) {
                    if(star >= vec[i].second) {
                        star += 1;
                        ans++;
                        vis[i].second = true;
                        change = true;
                        break;
                    }
                }
            }
            if(change) continue;
            int idx = -1;
            for(int i = 0; i < n; i++) {
                if(!vis[i].first) {
                    if(star >= vec[i].first) {
                        if(idx == -1 || vec[i].second > vec[idx].second) {
                            idx = i;
                        }
                    }
                }
            }
            if(idx != -1) {
                ++star;
                ++ans;
                vis[idx].first = true;
                change = true;
            }
            if(!change) break;
        }
        if(star < 2 * n) {
            printf("Case #%d: Too Bad\n", ++ca);
        }
        else {
            printf("Case #%d: %d\n", ++ca, ans);
        }
    }
    return 0;
}

