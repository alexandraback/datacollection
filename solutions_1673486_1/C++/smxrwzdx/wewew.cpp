#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
double P[100010];
double S[100010];
int A,B;
int main()
{
    freopen("AL.in","r",stdin);freopen("AAL.out","w",stdout);
    int i,j,k;
    int T,tt=0;
    double s;
    scanf("%d",&T);
    while(T--)
    {tt++;
        scanf("%d%d",&A,&B);
        for(i=1;i<=A;i++) scanf("%lf",&P[i]);
        s=1+B+1;S[0]=1.0;
        for(i=1;i<=A;i++)
        {
            S[i]=S[i-1]*P[i];
        }
        s=min(s,S[A]*(B-A+1)+(1-S[A])*(B-A+1+B+1));
        for(i=1;i<=A;i++)
        {
            s=min(s,S[A-i]*(i+B-A+i+1)+(1-S[A-i])*(i+B-A+i+1+B+1));
        }
        printf("Case #%d: %.6f\n",tt,s);
    }
}
