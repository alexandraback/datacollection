#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
struct person{
int D;
int M;
friend bool operator < (person x,person y)
 {
     return x.M<y.M;
 }
}P[20];

int main()
{
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("C-small-1-attempt0.out","w",stdout);
    int T,N,ca;
    cin>>T;
    for (ca=1;ca<=T;ca++)
        {   cin>>N;
            int nn;
            nn=0;
            for(int i=1;i<=N;i++)
            {
                int a,b,c;
                cin>>a>>b>>c;
                for (int j=1;j<=b;j++)
                {P[nn+j].D=a;P[nn+j].M=c+j;
                }
                nn+=b;
            }
            sort(P+1,P+1+nn);
            if ((720.0-P[1].D)/360.0*P[1].M<(360-P[2].D)/360.0*P[2].M)
            printf("Case #%d: %d\n",ca,1);
            else printf("Case #%d: %d\n",ca,0);



        }
    return 0;
}
