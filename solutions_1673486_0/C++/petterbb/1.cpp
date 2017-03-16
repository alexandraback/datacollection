#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
double p[100001];

int main(){
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
            tmp = B + 2;
            if(tmp < expected)
                expected = tmp;
        }
        if(A == 2){
            tmp = B+1-A + (1-p[0]*p[1])*(B+1);
            if(tmp < expected)
                expected = tmp;
            tmp = p[0]*(B + 1) + (1-p[0])*(B+1)*2;
            if(tmp < expected)
                expected = tmp;
            tmp = B + A + 1;
            if(tmp < expected)
                expected = tmp;
            tmp = B + 2;
            if(tmp < expected)
                expected = tmp;
        }
        if(A == 3){
            tmp = B + 1 - A + (1 - p[0]*p[1]*p[2])*(B+1);
            if(tmp < expected)expected = tmp;
            tmp = p[0]*p[1]*(B-A+3) + (1-p[0]*p[1])*(B-A+3+B+1);
            if(tmp < expected)expected = tmp;
            tmp = p[0]*(B-A+5) + (1-p[0])*(B-A+5+B+1);
            if(tmp < expected)expected = tmp;
            tmp = B + 2;
            if(tmp < expected)expected = tmp;
        }
        
        printf("Case #%d: %lf\n", cases, expected);
    }
    return 0;
}
