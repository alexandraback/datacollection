#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const double eps = 1e-9;
int arr[300],sum;
bool check(int n,double x,int k){
    double lim = arr[k] + sum * x;
    double left = 1.0 - x,det;
    for(int i=0;i<n;i++){
        if(i==k)continue;
        if(lim<=arr[i])continue;
        det = lim - arr[i];
        det/=sum;
        if(det>left)return false;
        left -= det;
    }
    return true;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int tt=0;tt<T;tt++){
        int n;
        scanf("%d",&n);
        sum = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            sum += arr[i];
        }
        double ans[300];
        for(int i=0;i<n;i++){
            double low = 0,mid,high = 1;
            ans[i] = 1;
            for(int k=0;k<200;k++){
                mid = (low+high)/2.0;
                if(check(n,mid,i)==false){
                    high = mid;
                    ans[i] = mid;
                }else{
                    low = mid;
                }
            }
        }
        printf("Case #%d: ",tt+1);
        double ss = 0;
        for(int i=0;i<n;i++){
            printf("%.6lf ",ans[i]*100);
            ss += ans[i];
        }
        puts("");
    }
}
