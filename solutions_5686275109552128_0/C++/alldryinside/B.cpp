#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <list>
#include <set>
#include <ctime>
#include <list>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define vi vector<int>
#define vd vector<double>
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
#define INF (1<<30)
using namespace std;

void slow(int case_id)
{
    printf("Case #%d: ", case_id);
    int i, P[10], D, j, k, ans, last;
    cin >> D;
    for(i = 0; i < D; ++i) cin >> P[i];
    vector<int> W;
    for(ans = 1; ans < 15; ++ans) {
        bool ok = false;
        for(i = 0; i < ans; ++i) {
            k = ans - i;
            W.clear();
            for(j = 0; j < D; ++j) W.pb(P[j]);
            for(j = 0; j < i; ++j) {
                sort(W.begin(), W.end());
                last = (int)W.size() - 1;
                if(W[last] > k) {
                    W.pb(W[last] - k);
                    W[last] = k;
                }
            }
            sort(W.begin(), W.end());
            last = (int)W.size() - 1;
            if(W[last] <= k) {
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    cout << ans << '\n';
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) slow(i);
    return 0;
}
