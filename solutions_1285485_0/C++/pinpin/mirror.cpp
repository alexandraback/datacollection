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
    int T, H, W, D;
    int i, j, k, a, b;
    int x, y, xx, yy;
    int sum;
    string s;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> H >> W >> D;
        for(j=0;j<H;j++) {
            cin >> s;
            for(k=0;k<s.size();k++) {
                if (s[k] == 'X') {
                    x = k - 1;
                    y = j - 1;
                }
            }
        }
        W -= 2;
        H -= 2;
        // cout << H << "," << W << endl;
        vector<double> vd;
        for(a=-60;a<=60;a++) {
            for(b=-60;b<=60;b++) {
                if ((a == 0) && (b == 0))
                    continue;
                if ((a+30) % 2) {
                    xx = (2*W-1-x) + W*(a-1);
                } else {
                    xx = x + W*a;
                }
                if ((b+30) % 2) {
                    yy = (2*H-1-y) + H*(b-1);
                } else {
                    yy = y + H*b;
                }
                if (abs(xx-x) > D)
                    continue;
                if (abs(yy-y) > D)
                    continue;
                // cout << xx << "," << yy << endl;
                if (D*D >= ((xx-x)*(xx-x)+(yy-y)*(yy-y))) {
//                    cout << "here" << endl;
                    vd.push_back(atan2(yy-y,xx-x));
                }
            }
        }
        sum = 0;
        sort(vd.begin(), vd.end());
        vd.push_back(10.0);
        for(j=0;j<(vd.size()-1);j++) {
            if ((vd[j]+0.00001) < vd[j+1]) {
                sum++;
            }
        }
        
        cout << "Case #" << i << ": " << sum << endl;
    }
    
    return 0;
}
