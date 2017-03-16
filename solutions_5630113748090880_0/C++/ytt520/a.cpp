#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <vector>
#include <cstdlib>
#include <set>
using namespace std;
#define LL long long
#define B 240
#define eps 1e-8
#define MP make_pair
#define Pi acos(-1.0)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define ls (o << 1)
#define rs (2*o + 1)
#define md ((ll + rr) >> 1)
#define lson ll, md, ls
#define rson md + 1, rr, rs
#define MOD 998244353
const int N = 2520;
int a[N],b[N];
int main()
{
    freopen("B-small-attempt0 (2).in","r",stdin);
    freopen("B-small-attempt0 (2).out","w",stdout);
    int t,cas = 1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(int i=1;i<=2*n-1;i++){
            for(int j=1;j<=n;j++){
                int tmp;
                scanf("%d",&tmp);
                a[tmp] ++;
            }
        }
        //printf("hehe %d\n",a[0]);
        int cnt = 0;
        for(int i=0;i<N;i++)
        if(a[i]%2){
            b[cnt++] = i;
        }
        printf("Case #%d:",cas++);
        for(int i=0;i<cnt;i++){
            printf(" %d",b[i]);
        }
        printf("\n");
    }
    return 0;
}
