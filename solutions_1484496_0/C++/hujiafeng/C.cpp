#include<iostream>
#include<memory.h>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cmath>

using namespace std;
int a[100];
int main()
{
      freopen("C-small-attempt0.in","r",stdin);
    freopen("c.out","w",stdout);
    int ca,n,i,j,T,k;
    scanf("%d",&ca);
    for(T=1;T<=ca;T++)
    {
        cout<<"Case #"<<T<<":"<<endl;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);

        long long Max=(1LL<<n)-1;
       // cout<<Max<<endl;
        bool b[300];
        bool flag=false;
      //  cout<<"hah"<<(1LL<<2)<<endl;
        //for(j=0;j<3;j++)
      //  {
          //  cout<<(5&(1LL<<j))<<"TT"<<endl;
           // if((5&(1LL<<j))>0) cout<<j<<endl;
       // }



        for(i=1;i<=Max;i++)
        {
             int suma=0,sumb=0;
            memset(b,0,sizeof(b));
            for(j=0;j<n;j++)
            {
                if((i&(1LL<<j))>0)
                {
                    b[j]=true;
                    suma+=a[j];
                }
            }

            for(k=1;k<=Max;k++)
            {
                if(k==i) continue;
                sumb=0;
                    for(j=0;j<n;j++)
                    if((k&(1LL<<j))>0 && b[j]==true) break;
                    else if((k&(1LL<<j))>0 ) sumb+=a[j];
                    if(j==n && suma==sumb) {flag=true;break;}
            }
            if(flag==true) break;
        }
        if(flag==true)
        {
           // cout<<i<<" "<<k<<endl;
           int ss=0;
            for(j=0;j<n;j++)
            if(b[j]==true)
            {
                if(ss==0) {cout<<a[j]; ss=1;}
                else cout<<" "<<a[j];
            }
            cout<<endl;
            ss=0;
            for(j=0;j<n;j++)
            if((k&(1LL<<j))>0)
            {
                if(ss==0) { ss=1;cout<<a[j];}
                else cout<<" "<<a[j];
            }
            cout<<endl;
        }
        else
        {
            printf("Impossible\n");
        }
    }
    return 0;
}
