#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int CAS, n;
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++){
        printf("Case #%d: ", cas);
        int a, b, k, ans = 0;
        scanf("%d%d%d", &a, &b, &k);
        for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
        if ((i & j) < k) ans++;
        printf("%d\n", ans);
    }
}
