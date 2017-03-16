#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;

struct node
{
       int a,b,c;
};


int t;
int J,P,S,K;

int b[11][11],c[11][11];
int ans;
node ans0[2111];
int main()
{
    int i,j,k,times;
    int tt;
    int xx,yy;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    cin>>t;
    for(times=1;times<=t;times++)
    {
        cin>>J>>P>>S>>K;
        
        cout<<"Case #"<<times<<": ";
        if(K>=S)
        {
            cout<<J*P*S<<endl;
            for(i=1;i<=J;i++)
            {
                for(j=1;j<=P;j++)
                {
                    for(k=1;k<=S;k++)
                    {
                         cout<<i<<' '<<j<<' '<<k<<endl;
                    }
                }
            }
            continue;
        }
        
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        
        ans=0;
        
        int c1[11],c2[11];
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(i=1;i<=J;i++)
        {
            for(j=1;j<=P;j++)
            {
                 c1[i]++;
                 c2[j]++;
                 
                 for(tt=1;tt<=K;tt++)
                 {
                 xx=1;
                 for(k=2;k<=S;k++)
                 {
                     if(true)
                     {
                     if(b[i][k]<b[i][xx])
                     {
                         xx=k;
                     }
                     else if(b[i][k]==b[i][xx] && c[j][k]<c[j][xx])
                     {
                         xx=k;
                     }
                     }
                     else
                     {
                         if(c[j][k]<c[j][xx])
                         {
                             xx=k;
                         }
                         else if(b[i][k]<b[i][xx] && c[j][k]==c[j][xx])
                         {
                             xx=k;
                         }
                     }
                     
                 }
                 
                 //cout<<i<<' '<<j<<' '<<tt<<' '<<"   "<<xx<<endl;
                 
                 b[i][xx]++;
                 c[j][xx]++;
                 
                 if(b[i][xx]>K || c[j][xx]>K)break;
                 
                 ans++;
                 ans0[ans].a=i;
                 ans0[ans].b=j;
                 ans0[ans].c=xx;
                 }
            }
            
            if(j<=P)break;
        }
        
        cout<<ans<<endl;
        for(i=1;i<=ans;i++)
        {
            cout<<ans0[i].a<<' '<<ans0[i].b<<' '<<ans0[i].c<<endl;
        }
    }
    
    
    return 0;
}



