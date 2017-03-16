#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

const long long M=4500000000000000000LL;

long long calc(long long r,long long n){
    long long a=r*2+n*2-1;
    if(M/n<a) return M;
    return n*a;
}

int main(){
    int tt,TT;
    long long r,t,L,R,M;
    scanf("%d",&TT);
    for( tt=0; tt<TT; tt++ ){
        cin >> r>> t;
        L=0;
        R=1000000000000000000LL;
        while(L<R-1){
            M=(L+R)/2;
            if(calc(r,M)<=t){
                L=M;
            }else{
                R=M;
            }
        }
        cout << "Case #" << tt+1 << ": " << L << endl;
    }
    return 0;
}
