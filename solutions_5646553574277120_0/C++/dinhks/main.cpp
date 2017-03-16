#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
using namespace std;
char x[1000];
char y[1000];
int a[1000];
int b[1000];
int c[1000];
int H;
int cal(int v,int c)
{
    int i,j;
    for(i=0;i<v;++i)
        b[i]=0;
        for(j=0;j<v;++j)
        b[j]=1000;
    for(i=0;i<H;++i)
        b[a[i]]=1;

    for(j=1;j<v;++j)
        {
                for(int t=1;t<j;++t)
                {
                    if(b[t]>0&&b[j-t]>0&&b[t]+b[j-t]<b[j])
                        b[j]=b[t]+b[j-1];
                }
        }
    for(j=1;j<v;++j)
        if(b[j]>1+c)
        return j;
    return -1;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,c,d,v;
    int l,s,k,t;
    cin>>t;
    for(i=1;i<=t;++i)
    {
        cin>>c>>d>>v;
         for(j=0;j<1000;++j)
            b[j]=0;
        for(j=0;j<d;++j)
        {
            cin>>a[j];
            b[a[j]]=1;
        }
        H=d;

        while(1)
        {
            int o = cal(v,c);
            if(o==-1)
                break;
            a[H++]=o;
        }

       // cout<<b[v]<<endl;
        cout<<"Case #"<<i<<": "<<H-d<<endl;
    }
    return 0;
}
