#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int num[100005];
double ABS(double a){
    if(a < 0)return -a;
    return a;
}
int main (){
    int T,ca=0;
    int n,sum,i,j,flag,MIN,pos;
    double avg,ans,rest;
    double left,right,mid,X;
    scanf("%d",&T);
    while(T--){
        ca++;
        printf("Case #%d:",ca);
        scanf("%d",&n);
        sum = 0;
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
            sum += num[i];
        }
        for(i=0;i<n;i++){
            left = 0.0;
            right = 100.0;
            while(ABS(right - left) > 1e-7){
                mid = (left + right) / 2;
                flag = 0;
                rest = 100.0-mid;
                for(j=0;j<n;j++){
                    if(i == j){
                        continue;
                    }
                    if(num[j] < num[i] + mid * sum){
                        num[j] + X*sum/100 >= num[i] + (mid/100)*sum;
                        X = 100*(num[i]-num[j] + (mid/100) * sum)/sum;
                        //printf("X = %lf rest %lf %lf\n",X,rest,num[i]-num[j] + mid * sum);
                        if(X > 0)rest -= X;
                     }
                }
                if(rest < 0)flag = 1;
                if(flag == 0)left = mid;
                else right = mid;
            }
            printf(" %lf",left);
        }
        printf("\n");
    }
    return 0;
}

