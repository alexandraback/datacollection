#include<iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

const int maxn = 200;
int T,n,nn;
int a[maxn];
int ans;


void init() {
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
}

void solve()
{
    double tmp,now;
    int ans1 = ans;
    now = double(ans*2)/n;
    int nn = n;
    for (int i = 0; i < n; i++)
        if (a[i] >= now) {
            nn--;
            ans1 -= a[i];
        }
    now = double(ans+ans1)/nn;
    for (int i = 0; i < n; i++){
        tmp = 100*(now-a[i])/ans;
        if (tmp <0) tmp = 0;
        cout << fixed << setprecision(6) << tmp <<' ';
    }

}

int main() {
    freopen("A-small-attempt4.in", "r", stdin);
    freopen("A-small-attempt4.out", "w", stdout);
    cin >> T;
    for (int test = 1; test <= T; test++) {
        cout << "Case #" << test << ": ";
        init();
        solve();
        cout << endl;
    }
    return 0;
}
