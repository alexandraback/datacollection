#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <string>
#include <time.h>

using namespace std;

typedef long long ll;

const int N = 111;
ll f[N][2][2][2];
int a[N], b[N], c[N]; 

int main() {
    int TESTS;
    scanf("%d", &TESTS);

    for (int _t = 1; _t <= TESTS; ++_t) {
        printf("Case #%d: ", _t);
        
        int A, B, C;
        cin >> A >> B >> C;

        int n = 50;
        for (int i = 1; i <= n; ++i) {
            a[i] = (A & 1);
            b[i] = (B & 1);
            c[i] = (C & 1);

            A >>= 1;
            B >>= 1;
            C >>= 1;
        }
        memset(f, 0, sizeof(f));

        f[n][0][0][0] = 1;
        for (int i = n; i; --i) {
            for (int c1 = 0; c1 < 2; ++c1) 
                for (int c2 = 0; c2 < 2; ++c2) 
                    for (int c3 = 0; c3 < 2; ++c3)  {
                        //if (f[i][c1][c2][c3]) cerr << i << " " << c1 << " " << c2 << " " << c3 << ": " << f[i][c1][c2][c3] << endl;
                        
                        int to1 = 1, to2 = 1, to3 = 1;
                        if (c1 == 0 && a[i] == 0) to1 = 0;
                        if (c2 == 0 && b[i] == 0) to2 = 0;
                        if (c3 == 0 && c[i] == 0) to3 = 0;
                        
                        for (int d1 = 0; d1 <= to1; ++d1)
                            for (int d2 = 0; d2 <= to2; ++d2) {
                                int d3 = (d1 & d2);
                                if (d3 > to3) continue;

                                int n1 = 0, n2 = 0, n3 = 0;
                                if (c1 == 1 || (d1 < to1)) n1 = 1; 
                                if (c2 == 1 || (d2 < to2)) n2 = 1; 
                                if (c3 == 1 || (d3 < to3)) n3 = 1; 

                                f[i - 1][n1][n2][n3] += f[i][c1][c2][c3];
                            }
                    }
        }
        cout << f[0][1][1][1] << endl;
         
        //cerr << "Test " << _t << " completed. Consumed time " << double(clock()) / CLOCKS_PER_SEC << endl;
    }


    
    return 0;
}
