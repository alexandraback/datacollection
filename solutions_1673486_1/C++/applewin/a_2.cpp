#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int A,B;
double ans;
double prob[100000];
double aaa[100000];
double bbb[100000];

int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i){
        scanf("%d%d", &A,&B);
        for(int j=0;j<A;++j){
            scanf("%lf", &prob[j]);
        }
        double c = 1, tmp;
        double mm = A + B + 1;
        for(int j=0;j<A;++j){
            c *= prob[j];
            tmp = (A-j-1 + B-j-1+1) + (1-c)*(B+1);
            if (tmp < mm) mm = tmp;
        }
        if (1+B+1 < mm) mm = 1+B+1;
        printf("Case #%d: %lf\n", i, mm);
    }
    return 0;
}
