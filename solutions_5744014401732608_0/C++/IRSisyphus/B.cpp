#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int T;

unsigned long long generatepow (int i){
    if (i == 0) return 1;
    return 2*generatepow(i-1);
}

int main(){
    freopen("small.in", "r", stdin);
    freopen("small.out", "w", stdout);
    scanf("%d\n", &T);
    for (int t = 1; t <= T; ++t){
        printf("Case #%d: ", t);

        int asize, require;
        cin >> asize >> require;

        unsigned long long *lastcolumn = new unsigned long long[asize];

        lastcolumn[0] = 1;

        for (int i = 1; i < asize - 1 ; i++){
            lastcolumn[i] = generatepow(i-1);
        }
        lastcolumn[asize - 1] = 0;
        for (int i = asize - 2; i >= 0; --i){
            if (require >= lastcolumn[i]){
                require-=lastcolumn[i];
                lastcolumn[i] = 1;
            } else lastcolumn[i] = 0;
        }
        if (require!= 0){
            cout << "IMPOSSIBLE" << endl;
            continue;
        } else {
            cout << "POSSIBLE" << endl;
            for (int i = 1; i <= asize; ++i){
                for (int j = 1; j <= i; ++j) printf("0");
                for (int j = i+1; j < asize; ++j) printf("1");
                if (i!= asize) cout << lastcolumn[i-1] << endl;
            }
        }
        delete []lastcolumn;
        printf("\n");
    }
}
