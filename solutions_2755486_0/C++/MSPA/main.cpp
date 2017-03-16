#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <assert.h>

#define file_name ""

typedef long long ll;

const int N = 1e5+5;

using namespace std;

struct pt
{
    int d,s,w,e;
    pt (){}
    pt (int _d, int _s, int _w, int _e):d(_d),s(_s),w(_w),e(_e){}
};

int cmp(pt a, pt b)
{
    return (a.d<b.d || (a.d==b.d && a.w<b.w));
}
int b[N];
int d,n,k,w,e,di,pi,si,s;
int main()
{
    // freopen(file_name".in","r",stdin);
    // freopen(file_name".out","w",stdout);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int Test;
    scanf("%d",&Test);
    vector <pt > at;

    for(int test=1;test<=Test;++test)
    {
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        at.clear();


        for(int i=0;i<n;++i)
        {
            scanf("%d%d%d%d%d%d%d%d",&d,&k,&w,&e,&s,&di,&pi,&si);
            while (k--)
            {
                at.push_back(pt(d,s,w,e));
                d+=di;
                w+=pi;
                e+=pi;
                s+=si;
            }
        }

        sort(at.begin(),at.end(),cmp);

        int ans=0,id=0;

        /*if (test==4)
        {


            break;
        }*/
        for(int i=0;i<at.size();++i) at[i].w+=50000, at[i].e+=50000;
        for(int i=0;i<at.size();++i)
        {
            if (i && at[i].d!=at[i-1].d)
            {
                for(int l=id;l<i;++l)
                    for(int j=at[l].w;j<at[l].e;++j)
                        if (b[j]<at[l].s) b[j]=at[l].s;
                id=i;
            }
            for(int j=at[i].w;j<at[i].e;++j)
                if (b[j]<at[i].s) {ans++; break;}
          //  printf("%d %d %d %d %d\n",at[i].d,at[i].w,at[i].e,at[i].s,ans);
        }

        printf("Case #%d: %d\n",test,ans);
    }
    return 0;
}
