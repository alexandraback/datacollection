#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int LLI;

LLI euklides(LLI a, LLI b){
    if(b==0)return a;
    return euklides(b, a%b);
}

bool isPowerOfTwo(LLI x){
    while(x!=1){
        if(x%2LL!=0LL)return false;
        x/=2LL;
    }
    if(x==1)return true;
    return false;
}

int main(){
    //ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        LLI p, q;
        char c;
        cin >> p >> c >> q;
        LLI NWW = euklides(p, q);
        p/=NWW;
        q/=NWW;
        if(!isPowerOfTwo(q)){
            //cout << "Case #" << t << "4: impossible\n";
            printf("Case #%d: impossible\n", t);
            continue;
        }
        int licznik=0;
        for( ; ; ){
            q/=(2LL);
            licznik++;
            long double a=(long double)p;
            long double b=(long double)q;
            if(a/b>=1)break;
        }
        printf("Case #%d: %d\n", t, licznik);
    }
}
