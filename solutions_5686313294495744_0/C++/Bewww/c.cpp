#include<stdio.h>
#include<algorithm>
#include<map>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
map<string,int> M;
int T;
int n;
int now;
int a[1011],b[1011];
int x[66000];
int two[20];
int xx[20],yy[20];
int bew=0;
char sss[1000];
int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small.txt","w",stdout);
    int i,j,k;
    int p,q,r;
    int d,dd,ddd;
    string t,tt,ttt;
scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
    scanf("%d",&n);
    M.clear();
    now=0;
    for(i=0;i<n;i++)
    {
        t = "";
        scanf("%s",sss);
        int rr =strlen(sss);
        for(int iii=0;iii<rr;iii++)
        {
            t += sss[iii];
        }
        if(M.find(t) == M.end())
        {
            M[t] = now;
            a[i] = now;
            now++;
        }
        else
        {
            a[i] = M[t];
        }

        tt = "";
        scanf("%s",sss);
        rr =strlen(sss);
        for(int iii=0;iii<rr;iii++)
        {
            tt += sss[iii];
        }
        if(M.find(tt) == M.end())
        {
            M[tt] = now;
            b[i] = now;
            now++;
        }
        else
        {
            b[i] = M[tt];
        }
    }
   //for(i=0;i<n;i++)printf(">> %d %d\n",a[i],b[i]);
    for(i=0;i<66000;i++)x[i]=0;
    r=1;
    for(i=0;i<n;i++)r*=2;
    x[0]=0;
    two[0]=1;
    for(i=1;i<20;i++)two[i] = two[i-1]*2;

    //printf(">>>>> %d\n",r);
    for(i=1;i<r;i++)
    {
        dd = i;
        ddd = 0;
        for(j=n;j>=0;j--)
        {
            if(two[j] <= dd)
            {
                dd -= two[j];
                p = i - two[j];
                q = p;
                bew++;
              //  for(k=0;k<=n;k++){xx[k]=0;yy[k]=0;}
                for(k=n;k>=0;k--)
                {
                    if(two[k] <= q)
                    {
                        q -= two[k];
                        xx[a[k]]=bew;
                        yy[b[k]]=bew;
                    }
                }
                if(xx[a[j]] == bew && yy[b[j]] == bew)
                {
                    if(ddd < x[p] + 1)ddd = x[p] + 1;
                }
                else
                {
                    if(ddd < x[p]) ddd = x[p];
                }
            }
        }
        x[i] = ddd;
    }
    //printf(">>>>> %d\n",r);
    //for(i=0;i<r;i++)printf("> %d %d\n",i,x[i]);
    printf("Case #%d: %d\n",ii,x[r-1]);

}


    return 0;
}
