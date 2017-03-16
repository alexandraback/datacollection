//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

double ar[1009],pr[100],ap[100];
string aa;

int  main()
{
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);

    long long i,j,k,N,T,S,ans,temp,cas=0,ans1,now,sum;
    double z,x;
    cin>>T;
    while(T--)
    {
        cas++;

        cin>>N;
        sum=0;

        for(i=1;i<=N;i++)
        {
            cin>>ar[i]>>pr[i]>>ap[i];
            sum+=pr[i];
            ar[i]=360-ar[i];
        }

        if(sum==1)
        {
            ans=0;
        }
        else
        {
            if(N==1)
            {
                z=(360.0-ar[1])*(1+ap[1])/360.0;
                x=z*360.0/ap[1];

                if(x+ar[1]*1.0<360.0*2.0) ans=0;
                else ans=1;

            }
            else
            {
                if(ar[1]>ar[2])
                {
                    swap(ar[1],ar[2]);
                    swap(pr[1],pr[2]);
                    swap(ap[1],ap[2]);

                }

                if(ar[1]==ar[2])
                {
                    if(ap[1]>ap[2])
                    {
                        swap(ap[1],ap[2]);
                    }
                    z=(360.0-ar[1])*ap[1]/360.0;
                    x=z*360.0/ap[2];

                    if(x+ar[1]<360.0*2.0) ans=0;
                    else ans=1;
                }
                else
                {
                    ans=0;

                    long long flag=0;

                    z=(360.0-ar[1])*ap[1]/360.0;
                    x=z*360.0/ap[2];

                    if(x+ar[1]<360.0*2.0) flag++;

                    swap(ar[1],ar[2]);
                    swap(pr[1],pr[2]);
                    swap(ap[1],ap[2]);

                    z=(360.0-ar[1])*ap[1]/360.0;
                    x=z*360.0/ap[2];

                    if(x+ar[1]<360.0*2.0) flag++;

                    if(flag==2) ans=0;
                    else ans=1;

                }
            }
        }

        printf("Case #%lld: %lld\n",cas,ans);

    }

}
