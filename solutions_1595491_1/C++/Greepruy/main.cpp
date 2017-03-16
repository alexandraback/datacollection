#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
struct NODE
{
    int n;
    int m;
    bool can;
};
NODE data[1000];
bool cmp(NODE a,NODE b)
{
    return a.m>b.m;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    int ci;
    int n,s,p;
    int i,j;
    int ans;
    for(ci=1;ci<=cas;ci++)
    {
        scanf("%d%d%d",&n,&s,&p);
        for(i=0;i<n;i++)
        {
            scanf("%d",&data[i].n);
            data[i].m=data[i].n/3;
            if(data[i].n%3)data[i].m++;
            if(data[i].n%3==1) data[i].can=false;
            else if(data[i].n==0) data[i].can=false;
            else data[i].can=true;
        }
        sort(data,data+n,cmp);
        ans=0;
//        cout << p << ' '<<  s << endl;
//        for(i=0;i<n;i++)
//        {
//            cout << data[i].n << ' ' << data[i].m << ' ' << data[i].can << endl;
//        }
        for(i=0;i<n;i++)
        {
//            cout << data[i].m << ' '<< p << ' ' << data[i].can << ' ' << s << endl;
            if(data[i].m>=p) ans++;
            else if(data[i].m==p-1 && data[i].can && s)
            {
                s--;
                ans++;
            }
//            cout << "--" <<ans << endl;
        }
        printf("Case #%d: %d\n",ci,ans);
    }
}
