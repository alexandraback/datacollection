#include <map>
#include <set>
#include <queue>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(a) a.begin(),a.end()
#define clr(a) memset(a,0,sizeof(a))
#define fill(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VII;

const double eps = 1e-8;
const double pi = acos(-1.0);

#define N 111111
int a[N];
int main(){
    freopen("A-large.in","r",stdin);
    freopen("1.txt","w",stdout);
    int tt, cal=0, k, n, i;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d%d",&k,&n);
        int ans = n, cnt = 0;
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        if(k==1){
            printf("Case #%d: %d\n",++cal, n);
            continue;
        }
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++){
            while(k<=a[i]){
                ans = min(ans, cnt+n-i+1);
                k += k-1;
                cnt++;
            }
            k += a[i];
        }
        ans = min(ans, cnt);
        printf("Case #%d: %d\n",++cal, ans);
    }
    return 0;
}
