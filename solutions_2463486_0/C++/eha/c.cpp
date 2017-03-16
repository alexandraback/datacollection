#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <complex>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

vector<long long> num;
vector<long long> aaa;

bool palin(long long x){
    char str[20];
    sprintf(str,"%lld",x);
    int l = strlen(str);
    int z = (l+1)/2;
    for(int i=0;i<z;i++) if(str[i] != str[l-1-i]) return false;
    return true;
}

int solve(){
    long long A,B;
    scanf("%lld%lld",&A,&B);
    return upper_bound(num.begin(),num.end(),B) - lower_bound(num.begin(),num.end(),A);
}

int main(){
    for(long long i=1;i<=10000000;i++){
        if(palin(i)){
            long long sq = i*i;
            if(palin(sq)) {
                num.push_back(sq);
                aaa.push_back(i);
            }
        }
    }

    int T;
    scanf("%d",&T);
    rep(C,T) printf("Case #%d: %d\n", C+1, solve());
}
