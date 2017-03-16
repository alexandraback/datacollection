#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define INF 1000000000;
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define EPS                         1e-9
#define all(a)                      a.begin(), a.end()
#define MAXSIZE                     2510

using namespace std;
typedef long long LL;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){
    int tc,n,cur;
    int count[MAXSIZE];
    vector<int> ans;
    scanf("%d",&tc);
    for(int tci=1;tci<=tc;tci++){
        scanf("%d",&n);
        ans.clear();
        memset(count,0,sizeof count);
        for(int i=1;i<2*n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&cur);
                count[cur]++;
            }
        }
        for(int i=1;i<MAXSIZE;i++){
            if(count[i]%2){
                ans.push_back(i);
            }
        }
        sort(all(ans));
        printf("Case #%d:",tci);
        for(int i=0;i<ans.size();i++){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
}