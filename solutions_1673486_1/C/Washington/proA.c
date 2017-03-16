#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 100005

double rate[MAXN];
double ratm[MAXN];

double get_answer(int A, int B, double *rate)
{
    int i;
    double ans = 0.0, temp = 0.0, tempA;
    
    temp = 1.0;
    ratm[0]=1.0;
    for(i=1;i<=A;i++){
        temp*=rate[i];
        ratm[i] =temp;
    }

    /* All Right */
    ans += temp*(B-A+1);
    /* Wrong*/
    ans += (1-temp)*(B-A+1+B+1);
    /*printf("ans 1 = %lf\n", ans);*/
    for(i=1;i<=A;i++){
        tempA = ratm[A-i]*(2*i+B-A+1) + (1-ratm[A-i])*(2*i+B-A+1+B+1);

        if(tempA < ans)
            ans = tempA;
        /*printf("ans 1 = %lf\n", tempA);*/
    }
    tempA = (1 + B + 1);
    if(tempA < ans)
        ans = tempA;
    /*printf("ans 1 = %lf\n", tempA);*/
    return ans;
}

int main()
{
    int T,A,B,i,j;
    double answer;
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d%d",&A,&B);
        for(j=1;j<=A;j++){
            scanf("%lf", &rate[j]);
        }
        answer = get_answer(A, B, rate);
        printf("Case #%d: %.6lf\n", i, answer);
    }
    return 0;
}
