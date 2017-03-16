#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for(int (i)=(s);(i)<(e);++(i))

using namespace std;
typedef long long LL;

int TC;
int N;
double s[205];
double sum;

bool check(double m){
    double tmp = 0;
    for (int i=0;i<N;++i){
        if (s[i]<m){
            tmp += (m-s[i]);
        }
    }
    return tmp >= sum;
}

int main(){
    scanf("%d", &TC);
    for (int tc=1;tc<=TC;++tc){
        scanf("%d", &N);
        sum = 0;
        for (int i=0;i<N;++i){
            scanf("%lf", &s[i]);
            sum += s[i];
        }
        
        
        double up = 2*sum;
        double low = 0;
        
        for (int i=0;i<=1000;++i){
            double m = (up+low)/2;
            
            if (check(m)){
                up = m;
            }else{
                low = m;
            }
        }
        
        printf("Case #%d:", tc);
        for (int i=0;i<N;++i){
            if (s[i]>=up){
                printf(" 0");
            }else{
                printf(" %.8f", ((up-s[i])*100.0)/sum);
            }
        }
        puts("");
    }


    return 0;
}
