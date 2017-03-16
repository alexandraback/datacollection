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

const int N = 100005;

int main()
{
#ifdef PKWV
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out","w",stdout);
#endif // PKWV
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        int k, c, s;
        scanf("%d%d%d", &k, &c, &s);
        printf("Case #%d:", cas);
        if(s * c >= k)
        {
            int n = (k + c - 1) / c;
            for(int i = 0; i < n; i++)
            {
                ll id = (i * c);
                for(int j = 1; j < c; j++) id = id * k + min(i*c+j,k-1);
                cout << ' ' << id + 1;
            }
            printf("\n");
        }
        else printf(" IMPOSSIBLE\n");
    }
    return 0;
}

