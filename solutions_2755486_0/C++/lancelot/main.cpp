#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct attack
{
    int S;
    int w,e;
    int t;
}tmp;
vector<attack>se;
int wall[1000];
bool comp(attack a,attack b)
{
    return a.t<b.t;
}
int N;
void raise(int w,int e,int s)
{
    for(int i=500+w*2;i<=500+e*2;i++)
        if(wall[i]<s)wall[i]=s;
}
bool tryattack(int w,int e,int s)
{
    //printf("%d %d %d\n",w,e,s);
    for(int i=500+w*2;i<=500+e*2;i++)
        if(wall[i]<s)return true;
    return false;
}
int main()
{

freopen("cs.in","r",stdin);
freopen("cs.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int C=1;C<=T;C++)
    {
        se.clear();
        int res=0;
        memset(wall,0,sizeof(wall));
        scanf("%d",&N);
        int d,n,w,e,s,deltad,deltap,deltas;
        for(int i=0;i<N;i++)
        {
            scanf("%d %d %d %d %d %d %d %d",&d,&n,&w,&e,&s,&deltad,&deltap,&deltas);
            for(int j=0;j<n;j++)
            {
                tmp.w=w+deltap*j;
                tmp.e=e+deltap*j;
                tmp.S=s+deltas*j;
                tmp.t=d+deltad*j;
                se.push_back(tmp);
            }
        }
        sort(se.begin(),se.end(),comp);
        //printf("%d %d\n",se[0].t,se[1].t);
        for(int i=0,j=i+1;i<se.size();i=j)
        {
            while(j<se.size()&&se[j].t==se[i].t)j++;
           // printf("%d:\n",se[i].t);
            for(int k=i;k<j;k++)
            {
                bool f=tryattack(se[k].w,se[k].e,se[k].S);
                if(f)
                    res++;
            }
            for(int k=i;k<j;k++)
            raise(se[k].w,se[k].e,se[k].S);
        }
        printf("Case #%d: %d\n",C,res);
    }
     return 0;
}
