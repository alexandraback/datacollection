#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<map>
using namespace std;

int main()
{
    int n,N,M;
    double p[100010];
    
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A_out.txt", "w", stdout);
    /*
    FILE *in = fopen("A_test.in","r");
    FILE *out = fopen("A_out.txt","w");
*/
    scanf("%d\n",&n);

    for(int Case=1; Case<=n; Case++){

        printf("Case #%d: ",Case);

        scanf("%d %d",&N,&M);
        //printf("%d %d\n",N,M);
        p[0] = 1;
        
        for(int i=1;i<=N;i++)
        {
            scanf("%lf",&p[i]);
            if(i)
                p[i] *= p[i-1];
        }
        
        double ans = 1e16;
        int ok = M-N+1;
        int no;
        double now_p;
        
        for(int i=0;i<=N;i++)
        {
            no = ok+M+1;
            now_p = (p[N-i])*ok + (1-p[N-i])*no;
           // printf("%.5lf %.5lf\n",ans,now_p);
            ans = ans<now_p?ans:now_p;
            ok += 2;
        }
        ans = ans<(M+2)?ans:(M+2);
        printf("%.6lf",ans);
        printf("\n");
    }

    return 0;
}

