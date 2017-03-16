#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
int val[10];
int e,r,totn;
long long maxgain;
void dfs(int i,int cen,long long int gain)
{
    int n=0,next;
    if(i==totn)
    {
        if(gain>maxgain)
            maxgain=gain;
        return;
    }
    while(n<=cen)
    {
        next=cen-n+r;
        if(next>e)
            next=e;
        dfs(i+1,next,gain+((long long)n*val[i]));
        n++;
    }
    return;
}
using namespace std;
int main()
{
    int t=1,T,i;
    scanf(" %d",&T);
    while(t<=T)
    {
        scanf(" %d %d %d",&e,&r,&totn);
        i=0;
        while(i<totn)
        {
            scanf(" %d",&val[i]);
            i++;
        }
        maxgain=0;
        dfs(0,e,(long long)0);
        printf("Case #%d: %lld\n",t,maxgain);
        t++;
    }
	return 0;
}
