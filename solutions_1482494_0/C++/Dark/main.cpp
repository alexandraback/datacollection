#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <string>
#include <set>
#include <cstring>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define sz(i) int(i.size())
#define mst(i,n) memset(i,n,sizeof(i))
#define eps 1e-9
#define INF 1e20
#define MOD 1000000007
#define LL long long
#define pi acos(-1)
LL gcd(LL a,LL b)
{
    if(a==0)return b;
    return gcd(b%a,a);
}
struct T
{
    int num;
    int fb;
    bool used;
} t[1<<11];
bool cmp(struct T a,struct T b)
{
    if(a.num==b.num)
        return a.fb>b.fb;
    return a.num<b.num;
}
int main()
{
    int T;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    For(ca,T)
    {
        int n;
        int a[1<<10],b[1<<10],c[1<<10],d[1<<10];
        scanf("%d",&n);
        For(i,n)
        {
            scanf("%d %d",&a[i],&b[i]);
            c[i]=a[i],d[i]=b[i];
            t[i*2].num=a[i];
            t[i*2].fb=(i+1);
            t[i*2].used=0;

            t[i*2+1].num=b[i];
            t[i*2+1].fb=-(i+1);
            t[i*2+1].used=0;
        }
        int ans=n*2;
        int front=n*2;
        sort(t,t+2*n,cmp);
        bool fg=1;
        for(int i=n*2-1; i>=0; i--)
        {
            if(t[i].used) continue;
            front--;
            //printf("#%d %d\n",t[i].num,front);
            if(t[i].num>i)
            {
                fg=0;
            }
            if(t[i].fb<0&&t[i].num<front)
            {
                int ind=-t[i].fb-1;
                For(j,i)
                {
                    if(t[j].fb==ind+1&&!t[j].used)
                    {
                        t[j].used=1;
                        ans--;
                        front--;
                        break;
                    }
                }
            }
        }
        if(!fg)
            printf("Case #%d: Too Bad\n",ca+1);
        else
            printf("Case #%d: %d\n",ca+1,ans);
    }
}
