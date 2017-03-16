#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <set>
#include <sstream>
#include <cstdio>
#define FOR(i,a,b) for(int i=(a);i<=(b); i++)
#define FR(i,b) for(int i=0; i<(b);i++)
#define DOWN(i,a,b) for(int i=(a); i >=(b); i--)
#define X first
#define Y second
#define XX first.first
#define XY first.second
#define YX second.first
#define YY second.second
using namespace std;

int n;
int a[2000];
int main() {
    std::ios::sync_with_stdio(false);
    freopen("B-small.in","r",stdin);
    freopen("output.txt","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> n;
        FOR(i,1,n) cin >> a[i];

        int res = 1000000000;
        FOR(pancake,1,1000) {
            int specialTime = 0;
            FOR(i,1,n) {
                if (a[i] < pancake) continue;
                specialTime += (a[i] - 1) / pancake;
            }
            res = min(res, specialTime + pancake);
        }
        cout << res << endl;
    }
    return 0;
}

