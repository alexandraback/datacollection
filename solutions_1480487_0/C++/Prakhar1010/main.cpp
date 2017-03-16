#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>


int main(int argc, const char * argv[])
{
    int numberCases,n;
    int p[200];
    double diff[200];
    double sum=0;
    scanf("%d",&numberCases);
    for (int i=0;i<numberCases; i++) {
        
        scanf("%d",&n);
        for (int j=0; j<n; j++) {
            scanf("%d",&p[j]);
            sum+=p[j];
        }
        diff[0]=0;
        for (int k=0; k<n-1; k++) {
            
                diff[k+1]=(double)(p[0]-p[k+1])/sum;
            
        }
        double temp=0;double x;
        for (int k=1; k<n; k++) {
            temp=temp+diff[k];
        }
        x=(double)(1 - temp)/n;
        
        double negTemp=0;int count=0;
        for (int k=1; k<n; k++) {
            if (x+diff[k]<0) {
                negTemp+=x+diff[k];
                count++;
            }
        }
        double subtract=0;
        subtract=(double)negTemp/(n-count);
        subtract=subtract* -1;
        if (x<0) {
            printf("Case #%d: 0.000000 ",i+1);
        }
        else {
            printf("Case #%d: %lf ",i+1,(x-subtract)*100);

        }
        for (int k=1; k<n; k++) {
            if (x+diff[k]<0) {
                printf("0.000000 ");
            }
            else {
                printf("%lf ",(x+diff[k]-subtract)*100);
                
            }
            
        }
        printf("\n");
        sum = 0.0;
    }
    
    return 0;
}
