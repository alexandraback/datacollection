#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int T,ca=0;
    scanf("%d",&T);
    while(T--)
    {
        int x,n,m;
        scanf("%d%d%d",&x,&n,&m);
        if (n>m) swap(n,m);
        printf("Case #%d: ",++ca);
        if (x==4) {if ((m<4)||(n<3))puts("RICHARD");
                   else puts("GABRIEL");
                    continue;
        }
        if (x==1) {puts("GABRIEL");continue;}
        if (x==2) {
            if ((n*m)&1)
            puts("RICHARD");
            else puts("GABRIEL");
            continue;
        }
        if (x==3) {
            if (((n*m)%3)||((n*m/3)==1))
            puts("RICHARD");
            else puts("GABRIEL");
            continue;
        }
    }
    return 0;
}