#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
double p[100001];

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t;
    cin >> t;
    for(int cases = 1; cases <= t; cases++){
        double expected = 0x7fffffff;
        
        int A, B;
        cin >> A >> B;
        for(int i = 0; i < A; i++)
            cin >> p[i];
        double tmp;
        if(A == 1){
            tmp = (B+1-A) + (1-p[0])*(B+1);
            if(tmp < expected)
                expected = tmp;
            tmp = B + A + 1;
            if(tmp < expected)
                expected = tmp;
        }
        else{
            double pright = 1;
            for(int i = 0; i < A-1; i++){
                pright *= p[i];
                tmp = pright*(A+B-2*i-1) +  (1-pright)*(A+2*B-2*i);
                if(tmp < expected)expected = tmp;
            }
            pright *= p[A-1];
            tmp = B+1-A + (1-pright)*(B+1);
            if(tmp < expected)expected = tmp;
            if(B + 2 < expected)expected = B + 2;
        }
        
        
        printf("Case #%d: %lf\n", cases, expected);
    }
    return 0;
}
