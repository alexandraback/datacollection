#include<stdio.h>
#include<memory.h>

int main(){
    freopen("input1.in","r",stdin);
    freopen("output1_lib.txt","w",stdout);

    int t=0;
    scanf("%d" ,&t);

    int i=0;
    for(i=0;i<t;i++){
        int m,n;
        scanf("%d %d",&m, &n);
        double *p=new double[m];
        double *pa=new double[m];
        int j=0;
        for(j=0;j<m;j++){
            scanf("%lf",&p[j]);
        }
        ///////init down
        double min=1<<30;
        double localMin=0;
        //no backspace keep typing
        for(j=0;j<m;j++){
            if(j!=0)
                pa[j]=pa[j-1]*p[j];
            else
                pa[j]=p[j];
        }
        double allRight=pa[m-1];
        localMin=allRight*(n-m+1)+(1-allRight)*(2*n-m+2);
        if(localMin<min){
            min=localMin;
        }
        //giving up
        localMin=n+2;
        if(localMin<min){
            min=localMin;
        }

        //backup j+1 th;
        for(j=0;j<m;j++){
            if(m-j-2>=0)
                localMin=pa[m-j-2]*(n+2*j+3-m)+(1-pa[m-j-2])*(2*n+2*j-m+4);
            else
                localMin=n+m+1;

            if(localMin<min){
                min=localMin;
            }
        }

        printf("Case #%d: %.6f\n",i+1,min);
    }
    return 0;
}

