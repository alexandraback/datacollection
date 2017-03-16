#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
using namespace std;


int d,t;
int p[1001];

int ans;
int max_p;
int main()
{
    int i,j,k,times;
    int xx,yy;
    
    freopen("B-small-attempt1.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    cin>>t;
    
    for(times=1;times<=t;times++)
    {
        cin>>d;
        
        
        max_p=-1;
        for(i=1;i<=d;i++)
        {
             cin>>p[i];
             max_p=max(max_p,p[i]);
        }
        ans=max_p;
        
        
        for(i=1;i<=max_p;i++)
        {
            k=0;
            for(j=1;j<=d;j++)
            {
                yy=p[j]/i;
                if(p[j]%i==0)
                {
                    yy--;
                }
                k+=yy;
            }
            //cout<<i<<' '<<k<<endl;
            ans=min(ans,k+i);
        }
        
        
        cout<<"Case #"<<times<<": "<<ans<<endl;
    }
    
    
    return 0;
}
