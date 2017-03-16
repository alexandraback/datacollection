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
    int i, P[1007], D, j, k, ans, rem;
    cin >> D;
    for(i = 0; i < D; ++i) cin >> P[i];
    int lb = 0, rb = 1007, it;
    for(it = 0; it < 20; ++it) {
        ans = (lb + rb) / 2;
        bool ok = false;
        for(i = 0; i < ans; ++i) {
            k = ans - i;
            rem = i;
            for(j = 0; j < D; ++j) {
                if(P[j] > k) {
                    rem -= P[j] / k;
                    if(P[j] % k == 0) ++rem;
                }
                if(rem < 0) break;
            }
            if(rem >= 0) {
                ok = true;
                break;
            }
        }
        if(ok) {
            rb = ans;
        }
        else {
            lb = ans + 1;
        }
    }
    cout << rb << '\n';
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) slow(i);
    return 0;
}
