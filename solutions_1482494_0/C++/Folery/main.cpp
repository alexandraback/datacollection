#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
typedef long long LL;
using namespace std;
const double PI=acos(-1.0);
struct Node
{
    int a,b,vis,gget;
};
Node p[1050];
int cmp(const Node x,const Node y)
{
    return x.a<y.a||(x.a==y.a&&x.b>=y.b);
}
int n;
int flag;
int ans;
int now;
void get()
{
    now=0;
    ans=0;
    int w=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(now>=p[i].b)
        {
            now+=2;
            w++;
            ans++;
            p[i].vis=1;
            p[i].gget=1;
        }
    }
    if(w==n)
    {
        ans=n;
        return;
    }
    while(1)
    {
        for(i=0;i<n;i++)
        {
            if(p[i].vis==0&&now>=p[i].a)
            {
                now+=1;
                p[i].vis=1;
                ans++;
                break;
            }
        }
        if(i==n&&w<n)
        {
            ans=-1;
            return;
        }
        bool flag=true;
        while(flag)
        {
            flag=false;
            for(i=0;i<n;i++)
            {
                if(p[i].gget==0&&now>=p[i].b)
                {
                    flag=true;
                    p[i].gget=1;
                    if(p[i].vis==0)
                        now+=2;
                    else now+=1;
                    p[i].vis=1;
                    w++;
                    ans++;
                }
            }
        }
        if(w==n)
            return;
    }
}
int main()
{
    FILE *fpr,*fpw;
    fpr=fopen("B-small-attempt1.in","rb");
    //fpr=fopen("in.txt","rb");
    fpw=fopen("out.txt","wb");
    int T,Case;
    int i,j;

    fscanf(fpr,"%d",&T);
    for(Case=1;Case<=T;Case++)
    {
        fscanf(fpr,"%d",&n);
        for(i=0;i<n;i++)
        {
            fscanf(fpr,"%d%d",&p[i].a,&p[i].b);
            p[i].vis=0;
            p[i].gget=0;
        }
        sort(p,p+n,cmp);
        get();
        //fprintf(fpw,"Case #%d: %d\n",Case,ans);
        if(ans==-1)
            fprintf(fpw,"Case #%d: Too Bad\n",Case);
        else
            fprintf(fpw,"Case #%d: %d\n",Case,ans);
    }
    fclose(fpr);
    fclose(fpw);
    return 0;
}
