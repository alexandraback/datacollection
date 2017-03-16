#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;
const int maxn = 2005;
const int bas = 2005;
int N,top;
//int n;
struct node
{
    int d,e,w,stgh;
    node() {}
    node(int _d,int _w,int _e,int _stgh)
    {
        d = _d;
        e = _e;
        w = _w;
        stgh = _stgh;
    }
} tt[maxn];
int height[400000],h2[400000];
bool cmp(const node &p,const node &q)
{
    return p.d < q.d;
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,ta=1;
    cin >> T;
    while(T--)
    {
        cin >> N;
        int i,j,k;
        int myd,myn,myw,mye,mys,dd,dp,ds;

        top = 0;
        int maxL = 0;
        for(i=0; i<N; i++)
        {
            cin >>myd>>myn>>myw>>mye>>mys>>dd>>dp>>ds;
            mye *= 2;
            myw *= 2;
            dp *= 2;

            mye += bas;
            myw += bas;
            for(j=0; j<myn; j++)
            {
                tt[top++] = node(myd+j*dd,myw,mye,mys);
                myw += dp;
                mye += dp;
                maxL = max(maxL,mye);
                mys += ds;
            }
        }
        sort(tt,tt+top,cmp);
        memset(height,0,sizeof(height));
        // int pred = -1;
        stack<node>S;
        //=======================================================
        int ans = 0;
        for(i=0; i<top; i++)
        {
            if(i==0 || tt[i].d==tt[i-1].d)
            {
                S.push(tt[i]);
            }
            else
            {
                memset(h2,0,sizeof(h2));
                while(!S.empty())
                {
                    node T = S.top();
                    S.pop();
                    int flag = 0;
                    for(j=T.w; j<=T.e; j++)
                    {
                        h2[j] = max(h2[j],T.stgh);
                        if(T.stgh > height[j])
                        {
                            flag = 1;
                        }
                    }
                 //   if(flag)
                 //      printf("day %d\n",T.d);
                    ans += flag;
                }
                S.push(tt[i]);
                for(j=0; j<=maxL; j++) height[j] = max(height[j],h2[j]);
            }
        }

        memset(h2,0,sizeof(h2));
        while(!S.empty())
        {
            node T = S.top();
            S.pop();
            int flag = 0;
            for(j=T.w; j<=T.e; j++)
            {
                h2[j] = max(h2[j],T.stgh);
                if(T.stgh > height[j])
                {
                    flag = 1;
                }
            }
          //  if(flag)
          //     printf("day %d\n",T.d);
            ans += flag;
        }
        //====================================================
        printf("Case #%d: %d\n",ta++,ans);
    }
    return 0;
}
