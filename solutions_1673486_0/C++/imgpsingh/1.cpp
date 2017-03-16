#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
double inp[100010],prob[100010],res;
int main()
{
    int T,Kase=1;
    scanf("%d",&T);
    while(T--){
        int A,B;
        scanf("%d %d",&A,&B);
        for(int i=0;i<A;i++)
            scanf("%lf",&inp[i]);
        prob[0]=1.0;
        for(int i=0;i<A;i++)
            prob[i+1]=prob[i]*inp[i];
        res=B+2;
        for(int i=1;i<=A;i++)
            res=min(res,(1.0-prob[i])*((B-i+1)+(A-i)+(B+1))+prob[i]*((B-i+1)+(A-i)));
        printf("Case #%d: %.7lf\n",Kase++,res);
        
    }   
return 0;
}
