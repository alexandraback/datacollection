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
    double C, F, X, R, ret, tm, tmp;
    
    cin >> T;

    for(t=1;t<=T;t++) {
        cin >> C >> F >> X;

        for(n=1;;n++) {
            tmp = X/(2.0+F*n)+(C-X)/(2.0+F*(n-1));
            if (tmp > 0)
                break;
        }
        n--;
        //        printf("n=%d\n", n);

        if (n == 0) {
            ret = X/2.0;
        } else {
            ret = X/(2.0+F*n);
            for(i=n-1;i>=0;i--) {
                ret += C/(2.0+F*i);
            }
        }

        printf("Case #%d: %.8f\n", t, ret);
    }
    
    return 0;
}

//
// C/2.0 + C/(2.0+F) + C/(2.0+F+F) + .. + C(2.0+F*(n-1)) + X(2.0+F*n)
//
