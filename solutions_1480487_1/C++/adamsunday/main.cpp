#include <stdio.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++){
        int n;
        long long sum=0;
        scanf("%d",&n);
        int *table=new int[n];
        double *table2=new double[n];
        for (int j=0;j<n;j++){
            int a;
            scanf("%d",&a);
            table[j]=a;
            sum+=a;
        }
        double help1=2.0*sum/(double)(n);
        double help2=0;
        int k=0;
        printf("Case #%d:",i);
        for (int j=0;j<n;j++){
            double result=100*(help1-table[j])/sum;
            if (result < 0) {
                help2+=result;
                k++;
            }
            table2[j]=result;
          //  printf(" %.7lf",result);
        }
        for (int j=0;j<n;j++){
            if (table2[j]< 0) printf(" %.7lf",0.00);
            else printf(" %.7lf",(table2[j]+help2/(n-k)));
        }
        printf("\n");

    }
    return 0;
}
