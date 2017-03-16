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

ll reverse(ll what) {
    ll res = 0;
    while(what > 0) {
        res *= 10;
        res += what%10;
        what /= 10;
    }
    return res;
}

int main(){
    int T;
    scanf("%d", &T);
    ll n;
    For(cases, T) {
        set<ll> visited;
        visited.insert(1LL);
        scanf("%lld", &n);
        if (n == 1) {
            printf("Case #%d: %d\n", cases+1, 1);
            continue;
        }
        queue<pair<ll, ll> > todo;
        todo.push(mp(1, 1));
        while(true) {
            pair<ll,ll> my = todo.front();
            todo.pop();
            if (my.first + 1 >= 0) {
                if (my.first + 1 == n) {
                    printf("Case #%d: %lld\n", cases+1, my.second + 1);
                    break;
                }
                if (!visited.count(my.first+1)) {
                    visited.insert(my.first+1);
                    todo.push(mp(my.first + 1, my.second + 1));
                }
            }
            ll reversed = reverse(my.first);
            if (reversed >= 0) {
                if (reversed == n) {
                    printf("Case #%d: %lld\n", cases + 1, my.second + 1);
                    break;
                }
                if(!visited.count(reversed)) {
                    visited.insert(reversed);
                    todo.push(mp(reversed, my.second + 1));
                }
            }
        }
        
    }

}
