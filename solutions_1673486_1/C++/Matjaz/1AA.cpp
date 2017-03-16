#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

int T;

double min(double a,double b){
       if (a<b) return a; else return b;
       }

int main(){
    scanf("%d",&T);
    for (int t=1;t<=T;t++){
        int a,b;
        double p[100005];
        long double s[100005];
        scanf("%d %d",&a,&b);
        for (int i=0;i<a;i++) scanf("%lf",&p[i]);
    
        double res=b+2;
        
        s[0]=1;
        for (int i=1;i<=a;i++) s[i]=s[i-1]*p[i-1];
         
        for (int i=0;i<=a;i++){
            double ans=2*i+b-a+1;
            ans=ans+(b+1)*(1-s[a-i]);
            res=min(res,ans);
            }
        printf("Case #%d: %.6f\n",t,res);
        }
    return 0;
    }
