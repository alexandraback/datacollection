#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int f[1010], l, r;

bool check(int x){
    string xx, yy;
    while(x){
        xx += x % 10 + '0';
        yy += x % 10 + '0';
        x /= 10;
    }
    reverse(xx.begin(), xx.end());
    return xx == yy;
}
void init(){
    memset(f, 0, sizeof(f));
    for(int i = 1; i * i <= 1000; ++i){
        if(check(i) && check(i * i))
            f[i * i] = 1;
    }
    for(int i = 1; i <= 1000; ++i) f[i] += f[i - 1];
}
int main(){
    int t, cas = 1;
    init();
    for(cin >> t; t--; ){
        printf("Case #%d: ", cas++);
        cin >> l >> r;
        cout << f[r] - f[l - 1] << endl;
    }
    return 0;
}
