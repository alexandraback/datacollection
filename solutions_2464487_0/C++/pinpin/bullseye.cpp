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
    long long ret;
    int i, j;
    long long r, t, l, h, m, tmp;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> r >> t;
        // cout << r << "," << t << endl;
        if ((2*r+1) > t) {
            ret = 0;
        } else {
            l = 1;
            h = 10;
            while (true) {
                tmp = (2*h*h-h+2*r*h);
                if (tmp > t) 
                    break;
                h *= 2;
            }
            for(j=0;j<1000;j++) {
                m = (l+h)/2;
                tmp = (2*m*m-m+2*r*m);
                if (tmp <= t) {
                    l = m;
                } else {
                    h = m;
                }
                // cout << l << "," << h << endl;
            }
            ret = l;
        }
        cout << "Case #" << i << ": " << ret << endl;
    }
    
    return 0;
}
