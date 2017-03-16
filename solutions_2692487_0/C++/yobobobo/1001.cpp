#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#define Hash1 (LL)11111
#define Hash2 (LL)13337
#define lson l,m,rt << 1
#define rson m + 1,r,rt << 1 | 1
#define eps 1e-8
#define ft first
#define sd second
#define zero(x) (((x)>0?(x):-(x))<eps)
#define LL long long
#define Test puts("END")
#define pi acos(-1.0)
#define clr(a,b) memset(a,b,sizeof(a));
using namespace std;
const int MOD = 1000000007;
const int INF = 1000000000;
const int N = 105;
const int M = 1 << 11;


int arr[N],n,a;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    for(int t = 1;t <= cas;t ++){
        scanf("%d%d",&a,&n);
        for(int i = 0;i < n;i ++)
            scanf("%d",&arr[i]);
        sort(arr,arr + n);
        int ans = n,cur = a,need = 0;
        for(int i = 0;i < n;i ++){
            bool special = false;
            if(cur <= arr[i]){
                while(cur <= arr[i] && !special){
                    if(cur - 1 == 0) special = true;
                    cur += cur - 1;
                    need ++;
                }
            }
            if(special == true) {
                ans = n;
                break;
            }
            cur += arr[i];
            ans = min(ans,need + n - 1 - i);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}