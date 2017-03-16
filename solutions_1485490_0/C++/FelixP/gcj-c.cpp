#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long LL;
typedef vector <int> vi;

#define INF 1000000000
#define PI 3.14159265

#define FOR(i,a,n) for(int i=a,_n=n; i<_n; ++i)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

#define DEBUG(x) cout << '>' << #x << ':' << x << '\n'

int n, m;
LL memo[105][105];

struct tdata {
       LL sum, type;     
}box[105], toy[105];

LL dp(int a, int b) {
    if ( a == n || b == m ) return 0;
    LL ret = -INF*INF;
    if ( box[a].type == toy[b].type ) {
       LL val = min(box[a].sum, toy[b].sum);
       box[a].sum -= val; toy[b].sum -= val;
       ret = val + max(dp(a+1, b), dp(a, b+1));
       box[a].sum += val; toy[b].sum += val;   
    }
    else {
         ret = max(dp(a+1, b), dp(a, b+1));     
    }     
    
    return memo[a][b] = ret; 
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int tcase = 0;
    int t; scanf("%d", &t);
    
    while (t--) {
          memset(memo, -1, sizeof memo);
          scanf("%d %d", &n, &m);
          FOR (i, 0, n) scanf("%lld %lld", &box[i].sum, &box[i].type);
          FOR (i, 0, m) scanf("%lld %lld", &toy[i].sum, &toy[i].type);       
          
          printf("Case #%d: ", ++tcase);
          printf("%lld\n", dp(0, 0));     
    }
    return 0;
}
