#include<iostream>
using namespace std;
bool sum[100];
int dd[10];
int main()
{
    int t,c,d,v,i,j,k,x;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        cin>>c>>d>>v;
        for(i=0;i<d;i++) cin>>dd[i];
        for(i=1;i<=v;i++) sum[i]=0;
        for(i=0;i<d;i++)
        {
            for(j=1;j<=c;j++)
            {
                for(x=v;x>=1;x--)
                {
                    if(sum[x]==1) sum[x+(j*dd[i])]=1;
                }
                sum[dd[i]*j]=1;
            }
        }
        
        int ans=0;
        bool all=1;
        for(x=1;x<=v;x++)
        {
            if(sum[x]==0) {all=0;break;}
        }
        while(!all)
        {
            ans++;
            int temp=x;
            for(j=1;j<=c;j++)
            {
                for(x=v;x>=1;x--)
                {
                    if(sum[x]==1) sum[x+j*temp]=1;
                }
                sum[temp*j]=1;
            }
            all=1;
            for(x=1;x<=v;x++)
            {
                if(sum[x]==0) {all=0;break;}
            }
        }
        cout<<"Case #"<<k<<": "<<ans<<endl;
    }
}