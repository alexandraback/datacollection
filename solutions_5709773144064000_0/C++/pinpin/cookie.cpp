#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int
main(void)
{
    int T;
    int t, i, j, n;
    double C, F, X, R, ret, tm;
    
    cin >> T;

    for(t=1;t<=T;t++) {
        cin >> C >> F >> X;

        ret = X / 2.0;

        tm = 0.0;
        R = 2.0;
        while (true) {
            tm = tm + C/R;
            R = R + F;
            if (ret < (tm+X/R)) {
                break;
            }
            ret = tm + X/R;
        }

        printf("Case #%d: %.8f\n", t, ret);
    }
    
    return 0;
}
