#include<bits/stdc++.h>

using namespace std;

int main(){

    long long dd2 = 2*2*2*2*2*2*2*2;
    long long dd3 = 3*3*3*3*3*3*3*3;
    long long dd4 = 4*4*4*4*4*4*4*4;
    long long dd5 = 5*5*5*5*5*5*5*5;
    long long dd6 = 6*6*6*6*6*6*6*6;
    long long dd7 = 7*7*7*7*7*7*7*7;
    long long dd8 = 8*8*8*8*8*8*8*8;
    long long dd9 = 9*9*9*9*9*9*9*9;
    long long dd10 = 100000000;
    
    long long d2 = dd2 * dd2 + 1;
    long long d3 = dd3 * dd3 + 1;
    long long d4 = dd4 * dd4 + 1;
    long long d5 = dd5 * dd5 + 1;
    long long d6 = dd6 * dd6 + 1;
    long long d7 = dd7 * dd7 + 1;
    long long d8 = dd8 * dd8 + 1;
    long long d9 = dd9 * dd9 + 1;
    long long d10 = dd10 * dd10 + 1;
    
    cout << "Case #1:" << endl;
    for (int i = 0; i < 500; i++){
        bitset<14> x(i);
        cout << 1 << x << 11 << x << 1 << " " << d2 << " " << d3 << " " << d4 << " "<< d5 << " " << d6 << " " << d7 << " " << d8 << " " << d9 << " " << d10 << endl;
    }

}

// in case this counts as " by Hand" here is a very breaf explenation. i used the fact that 1xxxxxx1 * 10000001 = 1xxxxxx11xxxxxx1 is true in any base. 