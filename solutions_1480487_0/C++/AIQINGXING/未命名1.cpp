#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a,b,c,d,e,f;
int t;
double fen[1050];
int zong;
int n;
double sum,l,r,mid;

int main()
{
    freopen("A-small-attempt0(2).in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>t;
    for (int cas=1;cas<=t;cas++)
    {
        cin>>n;
        sum=0;
        for (a=1;a<=n;a++) {cin>>fen[a]; sum+=fen[a];}
        printf("Case #%d: ",cas);
        for (int i=1;i<=n;i++)
        {
            l=0.0; r=1.0;
            while (r-l>=0.0000000001)
            {
                  double num=0;
                  mid=(l+r)/2;
                  double temp=fen[i]+sum*mid;
                  for (a=1;a<=n;a++)
                  if (a!=i)
                  {
                     if (fen[a]>=temp) continue;
                     num+=(temp-fen[a]+0.0)/sum;
                  }
                  if (num+mid<=1) l=mid; else r=mid;
            }
            printf(" %.7lf",l*100);
        }
        printf("\n");
    }
}
