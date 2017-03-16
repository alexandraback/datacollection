#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1010;
struct ad
{
    int a,b;
};


ad f[N];

bool cmp(ad a,ad b)
{
     return a.b<b.b;
}

int v[N];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n,i,j,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d%d",&f[i].a,&f[i].b);
        sort(f,f+n,cmp);
        memset(v,0,sizeof(v));
        int s=0;
        int cnt=0;
        int tm=0;
        while(cnt<n)
        {
            bool flag=false;
            for(i=0;i<n;i++)
            {
                if(s>=f[i].b&&v[i]!=2)
                {
                    flag=true;
                    if(v[i]==0) s+=2;
                    if(v[i]==1) s+=1;
                    v[i]=2;
                    cnt++;
                    tm++;
                    break;
                }
            }
            if(flag) continue;
            int id=-1;
            int mx=-1;
            for(i=0;i<n;i++)
            {
                if(v[i]==0&&s>=f[i].a&&f[i].b>=mx)
                {
                    mx=f[i].b;
                    id=i;
                }
            }
                if(id==-1) break;
                v[id]=1;
                s++;
                tm++;
        }
        printf("Case #%d: ",++cs);
        if(cnt<n) printf("Too Bad\n");
        else printf("%d\n",tm);
    }
    return 0;
}



