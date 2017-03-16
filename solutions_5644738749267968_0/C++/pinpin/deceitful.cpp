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
    int N;
    int n_w, n_d; 
    int pos_k, pos_n;
    double ken[1000], naomi[1000];
    
    cin >> T;

    for(t=1;t<=T;t++) {
        cin >> N;

        for(i=0;i<N;i++) {
            cin >> naomi[i];
        }
        for(i=0;i<N;i++) {
            cin >> ken[i];
        }
        sort(&naomi[0], &naomi[N]);
        sort(&ken[0], &ken[N]);

        n_w = 0;
        pos_k = N-1;
        for(pos_n=N-1;pos_n>=0;pos_n--) {
            if (naomi[pos_n] < ken[pos_k]) {
                pos_k--;
            } else {
                n_w++;
            }
        }

        n_d = N;
        pos_k = 0;
        for(pos_n=0;pos_n<N;pos_n++) {
            if (naomi[pos_n] < ken[pos_k]) {
                n_d--;
            } else {
                pos_k++;
            }
            //            printf("n_d = %d\n", n_d);
        }

        printf("Case #%d: %d %d\n", t, n_d, n_w);
    }
    
    return 0;
}
