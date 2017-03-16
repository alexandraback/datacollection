#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int M = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int CAS, r, c, w;
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++){
        scanf("%d%d%d", &r, &c, &w);
        int ans = 0;
        for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j += w)
            ans++;
        for (int i = 1; i < w; i++)
            ans++;
        printf("Case #%d: %d\n", cas, ans);
    }
}
