#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
int ntest;
int a,b;
double p[100005],s[100005];

int main(){
    freopen("A-small-attempt0.in","r",stdin); // 
    freopen("test.out","w",stdout);
    scanf("%d\n",&ntest);    
    for(int t=0; t<ntest; t++){          
        printf("Case #%d: ",t+1);   
        scanf("%d %d",&a,&b);
        for(int i=0; i<a; i++){
            scanf("%lf",&p[i]);            
        }
        s[0]=1.0;
        for(int i=1; i<=a; i++){
            s[i]=s[i-1]*p[i-1];
        }
        double res = b+2.0;
        for(int i=a; i>-1; i--){
            int temp=a-i;            
            double t = temp + s[i]*(b-a+temp+1) + (1-s[i])*(b-a+temp+b+2);
            res = min(res,t);           
        }
        printf("%.6lf",res);
        printf("\n");       
    }
    return 0;
}
