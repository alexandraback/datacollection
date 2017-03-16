#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, cc=0;
    long long int r, t;
    
    scanf("%d", &cas);
    while( cas-- ){
        cin >> r >> t;
        // 2*n^2 + (2r-1)n - t <= 0
        long long int b=2*r-1;
        long long int down=1, up=707106781, now, tmp;
        while( up-down>1 ){
            now = (down+up)/2;
            tmp = (t-2*now*now)/now;
            if( tmp<b )     up = now;
            else            down = now;
        }
        printf("Case #%d: ", ++cc);
        cout << down << endl;
    }
    
    return 0;
}
