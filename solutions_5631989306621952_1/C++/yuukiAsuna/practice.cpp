#include <bits/stdc++.h>
#define PB push_back
#define FT first
#define SD second
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int>  P;
const int N = 1e3 + 10,MOD = 7+1e9;
char ss[N];
int G[N*2];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T, ca = 0;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%s", ss);
        int len = strlen(ss);
        int l = N - 1, r = N + 1;
        G[N] = ss[0] - 'A';
        for(int i = 1;i < len;i ++) {
            int tmp = ss[i] - 'A';
            if(tmp >= G[l+1]) G[l--] = tmp;
            else G[r++] = tmp;
        }
        printf("Case #%d: ", ++ca);
        for(int i = l + 1;i < r;i ++) printf("%c", G[i] + 'A');
        printf("\n");
    }
    return 0;
}