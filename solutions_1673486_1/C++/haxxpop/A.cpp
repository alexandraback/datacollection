#include<stdio.h>
int a,b ;
double p[200000];

int main(){
    int t;
    scanf("%d",&t);
    for(int g = 0 ; g < t ; g++ ){
        scanf("%d %d",&a,&b);
        for(int i = 0 ; i < a ; i++ ) scanf("%lf",&p[i]);
        double accom = 1;
        double minn = 3 * b ;
        //printf("xx ");
        for(int i = 0 ; i <= a ; i++ ){
            int count1 = ( a - i ) + ( b - i + 1 ) ;
            int count2 = count1 + ( b + 1 ) ;
            double res = count1 * accom + count2 * ( 1 - accom ) ;
            if( res < minn ) minn = res ;
            accom *= p[i];
            //printf("%lf ",res);
        }
        //printf("\n");
        int count = 1 + ( b + 1 ) ;
        if( count < minn ) minn = count ;
        printf("Case #%d: %lf\n",g+1,minn);
    }
   // for(;;);
}
