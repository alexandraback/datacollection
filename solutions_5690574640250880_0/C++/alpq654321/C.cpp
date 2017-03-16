#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int A,B,C,i,T,j,k,l,t,d[105],now,Time;
bool FLAG;
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        Time++;
        printf("Case #%d:\n",Time);
        scanf("%d%d%d",&A,&B,&C);
        if (B==1)
        {
            for (j=1; j<=C; j++) printf("*\n");
            for (j=C+1; j<A; j++) printf(".\n");
            printf("c\n");
        } else
          if (A==1)
          {
              for (j=1; j<=C; j++) printf("*");
              for (j=C+1; j<B; j++) printf(".");
              printf("c\n");
          } else
          {
              FLAG=true;
              k=A*B-C;
              d[1]=min(k/2,B);
              if (k-d[1]*2==1) d[1]--;
              if (d[1]<=0) FLAG=false; else {
              d[2]=d[1]; k-=d[1]*2; now=2;
              while (k>0) {d[now+1]=min(k,d[now]); if (d[now+1]==1) {d[now]--; d[now+1]=2;}  now++; k-=d[now];}}
              for (i=2; i<=now; i++) if (d[i]>B || d[i]>d[i-1]) FLAG=false;
              if (d[1]==1 || d[now]<=1) FLAG=false;
              if (k==1){d[now=1]=1; FLAG=true;}
            if (!FLAG || now>A) {printf("Impossible\n"); continue;}
            cout<<'c';
            for (i=2; i<=d[1]; i++) cout<<'.';
            for (i=d[1]+1; i<=B; i++) cout<<'*'; cout<<endl;
            for (i=2; i<=now; i++)
            {
                for (j=1; j<=d[i]; j++) cout<<'.';
                for (j=d[i]+1; j<=B; j++) cout<<'*';
                cout<<endl;
            }
            for (i=now+1; i<=A; i++)
              {for (j=1; j<=B; j++) cout<<'*'; cout<<endl;}
          }
    }
    return 0;

}
