// User :: lovelotus ( Prem Kamal )

//#include<bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<string>
#include<utility>
#include<cctype>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<deque>

#define lli long long int
#define ulli unsigned long long int
#define F first
#define S second
#define pii pair<int,int>
#define pip pair<int,pii>
#define pis pair<int,string>
#define pll pair<lli,lli>

using namespace std;

int a[101];
int hsh[31],c,d,v,deno[31],ts=1;

void markAll( int val, int cnt)
{
    int i;
    if(cnt==0) return;
    int hsh1[v+1];
    for(i=0;i<=v;i++) hsh1[i]=0;
    for(i=0;i<=v;i++)
    {
        if(hsh[i] && i+val<=v) hsh1[i+val]=ts;
    }
    for(i=0;i<=v;i++)
    {
        if(!hsh[i])
        {
            if(hsh1[i])
                hsh[i]=hsh1[i];
        }
    }
    markAll(val,cnt-1);
}


void markIt( int pos, int cost )
{
    int i;
    //printf("%d %d : ",pos,cost);
    //for(i=0;i<=v;i++) printf("%d ",hsh[i]); printf("\n");
    if(pos==d) return;
    int hsh1[v];
    for(i=0;i<=v;i++) hsh1[i]=0;
    for(i=0;i<=v;i++)
    {
        if(hsh[i] && i+a[pos]<=v) hsh1[i+a[pos]]=1;
    }
     for(i=0;i<=v;i++)
    {
        if(!hsh[i])
        {
            if(hsh1[i])
                hsh[i]=hsh1[i];
        }
    }
    if(cost>1)
    {
        markIt(pos,cost-1);
    }
    else markIt(pos+1,c);
}

int rec( int cnt )
{
    int i;
    if(cnt==0)
    {
        for(i=0;i<=v;i++)
        {
            if(!hsh[i])
            {
                return 0;
            }
        }
        return 1;
    }
    for(i=1;i<=v;i++)
    {
        if(!deno[i])
        {
            ts++;
            int tempTs=ts;
            deno[i]=1;
            hsh[i]=1;
            markAll(i,c);
            int found=rec(cnt-1);
            if(found) return 1;
            for(i=0;i<=v;i++)
            {
                if(hsh[i]>=tempTs) hsh[i]=0;
            }
            deno[i]=0;
        }
    }
    return 0;
}


int main()
{
    freopen("C:\\Users\\lovelotus\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\lovelotus\\Desktop\\output.txt","w",stdout);
    int t,i,tst=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&c,&d,&v);
        for(i=0;i<d;i++)
        {
            scanf("%d",&a[i]);
            deno[a[i]]=1;
        }
        memset(deno,0,sizeof(deno));
        for(i=0;i<=v;i++) hsh[i]=0;
        hsh[0]=1;
        markIt(0,c);
        //for(i=0;i<=v;i++) printf("%d ",hsh[i]); printf("\n");
        int cnt=0;
        ts=2;
        for(cnt=0;cnt<=v;cnt++)
        {
            int found=rec(cnt);
            if(found) break;
        }
        printf("Case #%d: %d\n",tst,cnt);
        tst++;
    }
    return 0;
}
