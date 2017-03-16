#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define N 1010
using namespace std;
struct level{
    int x,y;
}a[N];
int T,n;
int ok[N];
bool cmp(level a,level b)
{
    if (a.y==b.y) return a.x>b.x;
    return a.y<b.y;
}
int nx[N],be[N];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("outb.txt","w",stdout);
    cin>>T;
    for (int ttt=1;ttt<=T;ttt++)
    {
        cin>>n;
        for (int k=1;k<=n;k++)
        {
            scanf("%d%d",&a[k].x,&a[k].y);
        }
        memset(ok,0,sizeof(ok));
        sort(a+1,a+1+n,cmp);
        int cnt=0;
        int now=0,flag=1;
        int ans=0;


        while (now<n&&flag)
        {
            int v=now+1;
            if (cnt>=a[v].y&&ok[v]==0)
            {
                now++;
                cnt+=2;
                ans++;
                ok[v]=2;
                continue;
            }
            else
            if (cnt>=a[v].y&&ok[v]==1)
            {
                now++;
                cnt+=1;
                ans++;
                ok[v]=2;
                continue;
            }
            else
            if (cnt<a[v].y)
            {

                while (cnt<a[v].y&&flag)
                {
                    int flag0=0;
                    for (int i=n;i>=v;i--)
                    {
                        if (ok[i]==0&&cnt>=a[i].x)
                        {
                            cnt+=1;
                            ok[i]=1;
                            ans++;
                            flag0=1;
                            break;
                        }
                    }
                    if (!flag0)flag=0;
                }

             /*   while (head>=v&&cnt<a[v].y)
                {
                    head=nx[n+1];
                    for (int i=head;i>=v;i=nx[i])
                    if (ok[i]==0&&cnt>=a[i].x)
                    {
                        cnt+=1;
                        ok[i]=1;
                        ans++;
                        nx[be[i]]=nx[i];
                        break;
                    }
                }
*/
            }
        }
        if (!flag)
        {
            printf("Case #%d: Too Bad\n",ttt);
        }
        else
            printf("Case #%d: %d\n",ttt,ans);
    }
    return 0;
}
