#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

double p[100005];
double right[100005];

int main(int argc, char** argv) {
    int T,cas=1,a,b;
    scanf("%d",&T);
    right[0]=1;
    while(cas<=T){
        scanf("%d%d",&a,&b);
        for(int i=1;i<=a;i++){
            scanf("%lf",&p[i]);
            right[i]=right[i-1]*p[i];
        }
        double r1=(b-a+1)*right[a]+(1-right[a])*(b-a+1+b+1);
        double r2=b+2;
        double res=10000000;
        if(r1<res) res=r1;
        if(r2<res) res=r2;
        for(int i=1;i<=a;i++){
            double r=right[a-i]*(i*2+b-a+1)+(1-right[a-i])*(i*2+b-a+1+b+1);
            if(r<res) res=r;
        }
        printf("Case #%d: %.6f\n",cas,res);
        cas++;
    }
    return 0;
}

