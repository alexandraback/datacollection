#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;

#define FILEIO
string _input="C-small-attempt0.in";
// string _input="C-large.in";

int a[22],n,tot;
int  f[22];
int bsum[22];
bool ok=false;
void dfs(int k, int diff)
{
    if(ok) return;
    if(k==n)
    {
        if(diff==0)
        {
            for(int i=0;i<n;i++)if(f[i]!=-1) ok=true;
            return;
        }
        return ;
    }
    if(diff+bsum[k]<0) return;
    if(diff-bsum[k]>0) return ;
    f[k]=-1;
    dfs(k+1,diff);
    if(ok) return;
    f[k]=0;
    dfs(k+1,diff+a[k]);
    if(ok) return;
    f[k]=1;
    dfs(k+1,diff-a[k]);
}
int main()
{
#ifdef FILEIO
    freopen(_input.c_str(),"r",stdin);
    freopen((_input+".out.txt").c_str(), "w", stdout);
#endif

    int T; scanf("%d",&T);
    for(int IT=0;IT<T;IT++)
    {
        scanf("%d",&n);
        tot=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            tot+=a[i];
        }
        sort(a,a+n,greater<int>());
        memset(f,-1,sizeof(f));
        memset(bsum,0,sizeof(bsum));
        for(int i=n-1;i>=0;i--)bsum[i]=bsum[i+1]+a[i];
        ok=false;
        dfs(0,0); // 0-1


        printf("Case #%d:\n", IT+1);
        if(!ok)
        {
            printf("Impossible\n");
            continue;
        }
        for(int ff=0;ff<=1;ff++)
        {
            bool first=true;
            for(int i=0;i<n;i++) if(ff==f[i])
            {
                if(!first)printf(" ");
                first=false;
                printf("%d",a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
