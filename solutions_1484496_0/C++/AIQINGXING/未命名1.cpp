#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a,b,c,d,e,f;
int t;
int fen[25];
int dp[2010000];
int zong;
int n;
double sum,l,r,mid;

int main()
{
    freopen("C-small-attempt1(1).in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>t;
    for (int cas=1;cas<=t;cas++)
    {
        int now=1,yao=0;
        cin>>n;
        sum=0;
        memset(dp,0,sizeof(dp));
        for (a=1;a<=n;a++) {cin>>fen[a]; sum+=fen[a];}
        for (a=1;a<=n;a++) now*=2;
        now--;
        printf("Case #%d:\n",cas);
        for (a=1;a<=now;a++)
        {
            int brr[20],num=0;
            int k=a,zong=0;
            while (k!=0)
            {
                  num++;
                  brr[num]=k%2;
                  k/=2;
            }
            for (b=1;b<=num;b++) if (brr[b]==1) zong+=fen[b];
            dp[zong]++;
            if (dp[zong]==2) {yao=zong; break;}
        }
        int nimabi=0;
        if (yao==0) cout<<"Impossible"<<endl;
        else
        {
            for (a=1;a<=now;a++)
            {
                if (nimabi==2) break;
                int brr[50],num=0;
                int k=a,zong=0;
                while (k!=0)
                {
                      num++;
                      brr[num]=k%2;
                      k/=2;
                }
                for (b=1;b<=num;b++) if (brr[b]==1) zong+=fen[b];
                int fuck=0;
                if (zong==yao)
                {
                   nimabi++;
                   for (b=1;b<=num;b++) if (brr[b]==1)
                   {
                       if (fuck!=0) cout<<' ';
                       cout<<fen[b];
                       fuck++;
                   }
                   cout<<endl;
                }
            }
        }
    }
}
        
        
        
