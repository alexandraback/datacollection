#include <cstdio>
#include <algorithm>
using namespace std;
#define ii 2
#define jj 3
#define kk 4

char ff[10]="10ijk\0";
int ope[5][5]={
    {0,0,0,0,0},
    {0,1,ii,jj,kk},
    {0,ii,-1,kk,-jj},
    {0,jj,-kk,-1,ii},
    {0,kk,jj,-ii,-1},
};
char s[10005];
int a[100005];
int fin(int x,int y)
{
    int flag=1;
    if (x<0) {
        flag*=-1;
        x=-x;
    }

    if (y<0) {
        flag*=-1;
        y=-y;
    }

    return flag*ope[x][y];
}
int main(int argc, char const *argv[])
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int T,ca=0;
    scanf("%d",&T);
    while(T--)
    {
        long long x,l;
        scanf("%lld%lld",&l,&x);
        scanf("%s",s);
        printf("Case #%d: ",++ca );
        int tmp=1;
        for (int i=0;i<l;i++)
        {
            for (int j=1;j<5;j++)
                if (s[i]==ff[j]) a[i+1]=j;
            tmp=fin(tmp,a[i+1]);
        }

        int base=1;
        for (int i=1;i<=(x%4);i++)
        {
            base=fin(base,tmp);
        }
        if (base!=-1) {puts("NO");continue;}
        long long le=x*l,ri=0;
        for (int i=1;i<min(4ll,x);i++)
            for (int j=1;j<=l;j++)
            a[i*l+j]=a[j];
        tmp=1;
        for (int i=1;i<=min(4ll,x)*l;i++)
        {
            tmp=fin(tmp,a[i]);
            // printf("%d\n",tmp );
            if (tmp==ii){
            // printf("%d~\n",i );
                le=i;
                break;
            }
        }
        tmp=1;
        for (int i=min(4ll,x)*l;i;i--)
        {
            tmp=fin(a[i],tmp);
            if (tmp==kk){
            // printf("%d~\n",i );
                ri=x*l-(min(4ll,x)*l-(long long)i);
                break;
            }
        }
        // printf("%lld %lld\n",le,ri );
        if (le<ri) puts("YES");
        else puts("NO");
    }
    return 0;
}