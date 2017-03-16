#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

#define LIM 100000+5

int A,B;
double arr[LIM];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int cases;
    double a,b;
    scanf("%d",&cases);
    for(int tt=1;tt<=cases;tt++){
        scanf("%d%d",&A,&B);
        for(int i=1;i<=A;i++){
            scanf("%lf",&arr[i]);
        }
        a=double(A);
        b=double(B);
        arr[0]=1.0;
        for(int i=1;i<=A;i++){
            arr[i] = arr[i] * arr[i-1];
        }
        double best=100000000.0;
        for(int i=0;i<=A;i++){
            double k=double(A-i);
            double curr=arr[i]*(b+1.0+2*k-a) + (1.0-arr[i])*(2.0*(b+1.0+k)-a);
            //printf("i=%d curr=%.6lf\n",i,curr);
            if(curr<best){
                best=curr;
            }
        }
        double last=0.0;
        if(A==B){
            last=arr[A] + (1.0-arr[A])*(b+2.0);
        }
        else{
            last=b+2.0;
        }
        if(last<best){
            best=last;
        }
        printf("Case #%d: %.9lf\n",tt,best);
    }
}
