#include <cstdio>
#include <iostream>
using namespace std;
int main (){
    int cases,A,B,i;
    double p[100000],product,expected,min;
    scanf("%d",&cases);
    for (i=1;i<=cases;i++){
        scanf("%d %d",&A,&B);
        for (int j=0;j<A;j++){
            scanf("%lf",&p[j]);
        }
        min=(B+2)*1.0;
        product=1;
        for (int j=0;j<A;j++){
            product*=p[j];
            expected=product*(A+B-2*j-1)+(1-product)*(A+2*B-2*j);
            if (expected<min){
                              min=expected;
            }
        }
        printf("Case #%d: %.6lf\n",i,min);
    }
    return 0;
}
