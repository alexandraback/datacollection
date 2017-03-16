#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int t,i,j;
    char in[10005];
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    scanf("%d\n",&t);
    for(int cnt = 1;cnt<=t;cnt++){
        int n;
        scanf("%d%s",&n,in);
        int ret = 0, sum =0;
        //printf("%s\n",in);
        for(i=0;i<=n;i++){
            ret = max(ret, i - sum);
            sum += in[i] - '0';
        }
        printf("Case #%d: %d\n", cnt, ret);
    }
    return 0;
}
