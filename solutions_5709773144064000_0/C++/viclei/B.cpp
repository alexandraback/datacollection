#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

ifstream in("Bin.txt");
FILE * out=fopen("Bout.txt","w");

int main() {
    int T;
    in >> T;
    for( int TC= 1; TC <=T; TC++ ) {
        double C, F, X;
        double r = 2;
        double ans = 0;
        in >> C >> F >> X;

        while ( C/r + X/(r+F) < X/r ) { //better to get a cookie farm
            ans += C/r;
            r += F;
        }
        ans += X/r;
        fprintf(out,"Case #%d: %.7f\n", TC, ans);
    }
    return 0;
}
