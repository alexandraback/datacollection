#include <iostream>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <numeric>
#include <list>
#include <stack>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <functional>

#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef  long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VII;
typedef priority_queue<int> PQI;
const int Mod = 1e9 + 7;
inline LL FIX(LL a) {return (a % Mod + Mod) % Mod;}
#define MP(x,y) make_pair(x,y)
#define LEN(x) ((int)x.length())
#define SZ(x) ((int)x.size())
#define take(x,y) (((x)>>(y)) & 1ll)
#define mv(n) (1<<(n))
#define what_is(x) cerr << #x << " is " << x << endl;
#define eb emplace_back
#define pb push_back
#define UNQ(x) (sort(begin(x),end(x)),x.erase(unique(begin(x),end(x)),end(x)))


int main(){
    
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,cas = 0;
    scanf("%d",&T);
    while(T--) {
        int n,ret = 0,sum = 0;
        cin>>n;
        string s;
        cin>>s;
        sum = s[0] - '0';
        for(int i = 1;i <= n;i++) {
            int cur = s[i] - '0';
            if(sum < i) {
                ret = ret + i - sum;
                sum = i;
            }
            sum += cur;
        }
        printf("Case #%d: %d\n",++cas,ret);
    }
    return 0;
}

















