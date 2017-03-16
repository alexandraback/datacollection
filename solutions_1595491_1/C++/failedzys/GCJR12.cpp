#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 105
#define maxm 35
int Numb[3],n,Lim,Dat[maxn],TT,Sur;
int Ans;
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&TT);
    for (int tt = 1; tt <= TT; tt++) {
        Ans = 0;
        scanf("%d%d%d",&n,&Sur,&Lim);
        int Lim1 = Lim*3-2,Lim2 = Lim * 3 - 4;
        memset(Numb,0,sizeof(Numb));
        for (int i = 1; i <= n; i++) {
            int tmp;
            scanf("%d",&tmp);
            if (tmp >= Lim1)
                Numb[0]++;
            else if (tmp >= Lim2 && tmp > 0)
                Numb[1]++;
            else
                Numb[2]++;
        }
        if (Lim == 0) {
            printf("Case #%d: %d\n",tt,n);
            continue;
        }
        printf("Case #%d: %d\n",tt,Numb[0] + min(Numb[1],Sur));
        
    }
    
}
