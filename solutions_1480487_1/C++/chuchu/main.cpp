#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int cnt;scanf("%d",&cnt);
        for(int i=1;i<=cnt;i++){
            int n; scanf("%d",&n);
            bool check[200]={0};
            double score[n],sum=0,total=0,avg=0;
            for(int j=0;j<n;j++){
                scanf("%lf",&score[j]);
                sum+=score[j];
            }
            printf("Case #%d:",i);
            for(int j=0;j<n;j++){
                double tmp=(sum*2-score[j])/(n-1);
                if(tmp>score[j]){ total++; avg+=score[j]; }
                else check[j]=1;
            }
            avg=(avg+sum)/total;
            for(int j=0;j<n;j++){
                if(check[j])printf(" 0.000000");
                else if(avg<score[j]) printf(" 0.000000");
                else printf(" %lf",(avg-score[j])/sum*100);
            }
            putchar('\n');
        }
}
