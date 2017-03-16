#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int A,B;
double ar[100000];
double prob[100001];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        scanf("%d%d",&A,&B);
        for(int i=0;i<A;i++)scanf("%lf",&ar[i]);
        prob[0]=1.0;
        for(int i=0;i<A;i++)
            prob[i+1] = prob[i]*ar[i];
        double ans = B+2;
        for ( int i=1;i<=A;i++){
            ans = min(ans,(1.0-prob[i])*(B-i+1 + A-i + B+1) + prob[i]*(B-i+1+A-i));  
        }
        printf("Case #%d: %.8lf\n",I,ans);
        
    }   
return 0;
}
