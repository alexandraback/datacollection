// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 105;
const int INF = 0x3f3f3f3f;
const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int n,s,p;
int ms[M];
int mn[M];

void compute_best(int index, int score) {
    for(int a=0;a<=10;++a)
        for(int b=0;b<=10;++b)
            for(int c=0;c<=10;++c) {
                int mins = min(min(a,b),c);
                int maxs = max(max(a,b),c);
                if(a + b + c != score) continue;
                if(maxs-mins >=3) continue;
                if(maxs-mins == 2) {
                    ms[index] = max(ms[index], maxs);
                } else {
                    mn[index] = max(mn[index], maxs);
                }
            }
}

int memo[M][M];

int best(int remaining, int index) {
    int &ans = memo[remaining][index];
    if(ans != -1) return ans;
    if(index == n) {
        if(remaining == 0)
            return ans = 0;
        else
            return ans = -INF;
    }
    ans = best(remaining, index +1);
    if(ms[index] != -1 && ms[index] >=p && remaining >0)
        ans = max(ans, 1 + best(remaining -1, index + 1));

    if(ms[index] != -1 && ms[index] < p && remaining >0)
        ans = max(ans, best(remaining -1, index + 1));

    if(mn[index] != -1 && mn[index] >=p)
        ans = max(ans, 1 + best(remaining, index +1));

    return ans;
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t) {
        scanf("%d %d %d",&n,&s,&p);
        SET(ms,-1);
        SET(mn,-1);
        int score;
        for(int i=0;i<n;++i) {
            scanf("%d",&score);
            compute_best(i,score);
        }
        SET(memo,-1);
        int ans = best(s,0);
        //ans = max(0,ans);
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}

