#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int mn=1010;
int n,ans1,ans2;
double a[mn],b[mn];
bool u[mn];
void solve1()
{
    memset(u,0,sizeof u);
    ans1=0;
    fo(i,1,n)
        fo(j,1,n)
        {
            if(b[j]>a[i])break;
            if(!u[j])
            {
                u[j]=1,++ans1;
                break;
            }
        }
}
void solve2()
{
    memset(u,0,sizeof u);
    ans2=0;
    fo(i,1,n)
    {
        bool flag=0;
        fo(j,1,n)
        {
            if(b[j]>a[i]&&!u[j])
            {
                u[j]=1,flag=1;
                break;
            }
        }
        if(flag)continue;
        ++ans2;
        fo(j,1,n)
            if(!u[j])
            {
                u[j]=1;
                break;
            }
    }
}
int main()
{
    int Q;
    scanf("%d",&Q);
    fo(T,1,Q)
    {
        scanf("%d",&n);
        fo(i,1,n)scanf("%lf",a+i);
        fo(i,1,n)scanf("%lf",b+i);
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        solve1();
        solve2();
        printf("Case #%d: %d %d\n",T,ans1,ans2);
    }
    return 0;
}
