#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int mn=110;
int a[mn][mn],h1[mn],h2[mn];
int Q,T,n,m;
bool check()
{
    int i,j;
    fo(i,1,n)h1[i]=0;
    fo(i,1,m)h2[i]=0;
    fo(i,1,n)
        fo(j,1,m)
        {
            h1[i]=max(h1[i],a[i][j]);
            h2[j]=max(h2[j],a[i][j]);
        }
    fo(i,1,n)
        fo(j,1,m)
            if(h1[i]>a[i][j]&&h2[j]>a[i][j])
                return 0;
    return 1;
}
int main()
{
    scanf("%d",&Q);
    fo(T,1,Q)
    {
        scanf("%d%d",&n,&m);
        int i,j;
        fo(i,1,n)
            fo(j,1,m)
                scanf("%d",a[i]+j);
        printf("Case #%d: ",T);
        if(check())puts("YES");
        else puts("NO");
    }
    return 0;
}
