#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define ll long long
#define point pair<double, double>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define uint unsigned int
#define double long double
#define merge botva
#define M_PI 3.14159265358979323846

const int maxn = 5000000, maxt = 100020, INF = 1200000000;

#define big pair<int, string>
#define mp make_pair
#define y second

int n, m;
int a[maxn];

int main() {
        //freopen("ellipse.in", "r", stdin);
        //freopen("ellipse.out", "w", stdout);
       
        int t;
        cin >> t;
        for (int gi = 0; gi < t; ++gi) {
                int A;
                cin >> A >> n;
                for (int i = 0; i < n; ++i) {
                        scanf("%d", &a[i]);
                }
                long long sum = A;
                sort(a, a + n);
                int ans = n;
                int hm = 0;
                int bad = 0;
                for (int i = 0; i < n; ++i) {
                        if (a[i] < sum) sum += a[i];
                        else {
                                while (sum <= a[i]) {
                                        if (sum - 1 <= 0) {
                                                bad = 1;
                                                break;
                                        }
                                        ++hm;
                                        sum = sum + sum - 1;
                                }
                                sum += a[i];
                                if (bad) break;
                        }
                        ans = min(ans, hm + n - i - 1);
                        
                }
                printf("Case #%d: %d\n", gi + 1, ans);
        }
}
