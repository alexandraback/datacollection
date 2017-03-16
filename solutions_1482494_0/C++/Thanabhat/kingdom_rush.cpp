/*
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

struct st{
    int a,b;
    bool operator < (struct st o) const{
        if(b<o.b) return true;
        else if(b>o.b) return false;
        else if(a<o.a) return true;
        else return false;
    }
};

struct st ar[1005];
bool arb[1005][2];

bool solve(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&ar[i].a,&ar[i].b);
    sort(ar,ar+n);
    for(int i=0;i<n;i++)
    {
        arb[i][0]=false;
        arb[i][1]=false;
    }
//    for(int i=0;i<n;i++)
//        printf("%d %d\n",ar[i].a,ar[i].b);
    int cur_level=0,cur_star=0,sol=0;
    while(cur_level<n)
    {
        if(ar[cur_level].b<=cur_star)
        {
            sol++;
            if(!arb[cur_level][0])
            {
                arb[cur_level][0]=true;
                cur_star++;
            }
            if(!arb[cur_level][1])
            {
                arb[cur_level][1]=true;
                cur_star++;
            }
            cur_level++;
        }else
        {
            int lvl=-1;
            for(int i=n-1;i>=cur_level;i--)
            {
                if(!arb[i][0]&&ar[i].a<=cur_star)
                {
                    lvl=i;
                    break;
                }
            }
            if(lvl==-1)
            {
                printf("Too Bad\n");
                return 0;
            }
            if(!arb[lvl][0])
            {
                arb[lvl][0]=true;
                cur_star++;
                sol++;
            }
        }
    }
    printf("%d\n",sol);
    return true;
}

int main(){

    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}
