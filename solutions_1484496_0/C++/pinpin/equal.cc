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
    int T, N;
    int i, j, k;
    long long ll;
    int m0, m1;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> N;
        vector<int> v(N);
        for(j=0;j<N;j++) {
            cin >> v[j];
        }

        map<long long, int> mymap;
        bool found = false;

        for(j=1;j<(1 << N);j++) {
            found = false;
            ll = 0;
            for(k=0;k<N;k++) {
                if (j & (1 << k))
                    ll += v[k];
            }
            if (mymap.find(ll) != mymap.end()) {
                found = true;
                m0 = mymap[ll];
                m1 = j;
            } else {
                mymap[ll] = j;
            }
            if (found)
                break;
        }

        if (found) {
            bool fst = true;
            printf("Case #%d:\n", i);
            for(j=0;j<N;j++) {
                if (m0 & (1 << j)) {
                    if (!fst) {
                        printf(" ");
                    }
                    fst = false;
                    printf("%d", v[j]);
                }
            }
            printf("\n");
            fst = true;
            for(j=0;j<N;j++) {
                if (m1 & (1 << j)) {
                    if (!fst) {
                        printf(" ");
                    }
                    fst = false;
                    printf("%d", v[j]);
                }
            }
            printf("\n");
        } else {
            printf("Case #%d:\nImpossible\n", i);
        }        
    }
    
    return 0;
}
