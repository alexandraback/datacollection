#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;
#define ll long long
const long long LINF = ~(((long long)0x1)<<63)/2;
const int INF=0X3F3F3F3F;
const double eps=1e-7;
int main()
{
    freopen("B-small-attempt0.in.txt","r",stdin);
    freopen("B-small-attempt0.out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int num=1;
        int now=0;
        int d=1;
        string sx,sy;
        while(abs(now)!=abs(x))
        {
            now+=d*num;
            if(d==1)
                sx.push_back('E');
            else
                sx.push_back('W');
            num++;
            d=-d;
        }
        int nowx=now,nowy;
        d=1;
        now=0;
        while(abs(now)!=abs(y))
        {
            now+=d*num;
            if(d==1)
            sy.push_back('N');
            else
                sy.push_back('S');
            num++;
            d=-d;
        }
        nowy=now;
        printf("Case #%d: ",cas);
        if(nowx==x)
            cout<<sx;
        else
        {
            for(int i=0;i<sx.size();i++)
                if(sx[i]=='E')
                    printf("W");
                else
                    printf("E");
        }
        if(nowy==y)
            cout<<sy;
        else
        {
            for(int i=0;i<sy.size();i++)
                if(sy[i]=='N')
                    printf("S");
                else
                    printf("N");
        }
        puts("");
    }
    return 0;
}





