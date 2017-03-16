//#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<list>
//#include<ext/rope>
#define PB push_back
#define MP make_pair
#define PF push_front
#define lson k<<1
#define rson k<<1|1
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;

const int N = 2505;
int cnt[N];

int main()
{
#ifdef PKWV
    freopen("in.in", "r", stdin);
#endif // PKWV
//    freopen("B-small-attempt0.in","r",stdin);
//    freopen("B-small.out","w",stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        memset(cnt, 0, sizeof(cnt));
        int n;
        scanf("%d", &n);
        for(int i = 1; i < 2 * n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int t;
                scanf("%d", &t);
                cnt[t]++;
            }
        }
        printf("Case #%d:", cas);
        for(int i = 0; i < N; i++) if(cnt[i] & 1) printf(" %d", i);
        printf("\n");
    }
    return 0;
}

