#include<iostream>
#include<cstdlib>
#include<cstdio>

void work() {
    double result;
    double prob = 1;
    int A,B;
    scanf("%d%d",&A,&B);
    result = B+2;
    for(int i =1; i <= A;i++){
        double p;
        scanf("%lf",&p);
        prob *=p;
        double expect = prob * (A-i + B-i + 1) + (1-prob) * (A-i + B-i + 1 + B+1);
//        printf("%lf %lf\n", prob, expect);
        if (expect < result)
            result = expect;
    }
    printf("%.6lf", result);
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i =1; i <=t;i++) {
        printf("Case #%d: ",i);
        work();
        printf("\n");
    }
}
