#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int i,j,k;
    int T;
    int H,h;
    scanf("%d",&T);
    int X,Y;
    int tt=0,s;
    while(T--)
    {tt++;
        scanf("%d%d%d",&N,&X,&Y);
        s=fabs(X)+fabs(Y);
        for(H=0;;H++)
        {
            if(N<=4*H+1) break;
            else
            {
                N-=4*H+1;
            }
        }
        printf("Case #%d: ",tt);
        double ans,p;
        if(s<2*H) printf("1.0\n");
        else if(s==2*H)
        {
            if(N==4*H+1) printf("1.0\n");
            else
            {
                if(Y==2*H) printf("0.0\n");
                else
                {
                    Y++;
                    H*=2;
                    //cout<<Y<<"  "<<H<<"   "<<N<<endl;
                    if(N<=H)
                    {
                        j=0;
                        ans=0.0;p=1.0;
                        for(i=1;i<=Y;i++)
                        {
                            p*=(N+1-i);p/=i;
                            while(p>1e10&&j<N)
                            {
                                p/=2;j++;
                            }
                        }
                        ans=p;
                        for(i=Y+1;i<=min(H,N);i++)
                        {
                            p/=i;p*=(N+1-i);
                            ans+=p;
                            while(p>1e10&&j<N)
                            {
                                ans/=2;p/=2;
                            }
                        }
                        while(j<N)
                        {
                            ans/=2;j++;
                        }
                        printf("%.10f\n",ans);
                    }
                    else
                    {
                        if(Y<=N-H) printf("1.0\n");
                        else
                        {
                            j=0;
                            ans=0.0;p=1.0;
                            for(i=1;i<=Y;i++)
                            {
                                p*=(N+1-i);p/=i;
                                while(p>1e10&&j<N)
                                {
                                    p/=2;j++;
                                }
                            }
                            ans=p;
                            for(i=Y+1;i<=N;i++)
                            {
                                p/=i;p*=(N+1-i);
                                ans+=p;
                                while(p>1e10&&j<N)
                                {
                                    ans/=2;p/=2;
                                }
                            }
                            while(j<N)
                            {
                                ans/=2;j++;
                            }
                            printf("%.10f\n",ans);
                        }
                    }
                }
            }
        }
        else printf("0.0\n");
    }
    return 0;
}
