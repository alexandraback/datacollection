#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<map>
using namespace std;

int main()
{
    int n,N,M;
    int j[250];
    
    freopen("A-large.in", "r", stdin);
    freopen("A_out.txt", "w", stdout);
    /*
    FILE *in = fopen("A_test.in","r");
    FILE *out = fopen("A_out.txt","w");
*/
    scanf("%d\n",&n);

    for(int Case=1; Case<=n; Case++){

        printf("Case #%d:",Case);

        scanf("%d",&N);
        //printf("%d %d\n",N,M);]
        double x = 0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&j[i]);
            
            x += (double)j[i];
        }
     //   printf("\n");

        double x2 = x*2;
      //  printf("\n%lf  %lf\n",x,x2);
        double aver = x2/(double)N;
        int people = N;
        for(int i=1;i<=N;i++)
            if(j[i]>aver)
            {
               people--;
               x2 -= j[i]; 
            }
        aver = x2/(double)people;
       // printf("\n%.5lf  %.5lf   %d\n",aver,x2,people);
        for(int i=1;i<=N;i++)
        {
            double ans = (aver-(double)j[i])/x*100;
            
            if(ans<0)
                ans = 0;
            printf(" %.5lf",ans);
        }
        printf("\n");
    }

    return 0;
}

