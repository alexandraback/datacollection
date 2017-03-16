#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <error.h>

#define SIZE 200

void output(int i, int judges, double y[SIZE]){
    int j;
    printf("Case #%d: ",i);
    for(j=0;j<judges;j++){
        printf("%lf ",y[j]);
    }
    printf("\n");
    
    return;
}

int main(void){
    int t;
    int n;
    int judge[SIZE];
    double y[SIZE];
    int i,j;
    int sum;
    int supersum=0;
    int supercontestant = 0;
    
    //read the data num
    scanf("%d\n",&t);
    
    for(i=1;i<=t;i++){
        //read the data
        sum = 0;
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%d",judge+j);
            sum += judge[j];
        }
        supersum = sum;
        supercontestant = 0;
        memset(y, 0, SIZE);
        //calc
        for(j=0;j<n;j++){
            y[j] = 2.0/n - judge[j]*1.0/sum;
            y[j] *= 100;
            if(y[j]<0){
                supersum -= judge[j];
                supercontestant++;
                y[j] = 0;
            }
        }
        for(j=0;j<n;j++){
            if(n>supercontestant && sum > 0){
                y[j] = (1.0+supersum*1.0/sum)/(n - supercontestant) - judge[j]*1.0/sum;
            }
            y[j] *= 100;
            if(y[j] < 0){
                y[j] = 0;
            }
        }
        //output the line
        output(i,n,y);
    }
    
    return 0;
}

