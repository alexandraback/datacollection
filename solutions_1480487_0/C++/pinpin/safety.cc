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
    int T, N, NN;
    int i, j, k;
    int sum;
    double sumd;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> N;
        sum = 0;
        vector<int> s(N);
        for(j=0;j<N;j++) {
            cin >> s[j];
            sum += s[j];
        }
        NN = N;

        vector<int> m(N);
        //        cout << t[0] << "," << t[1] << endl;

        vector<double> d(N);
        sumd = 0;
        for(j=0;j<N;j++) {
            if (N*s[j] >= sum*2) {
                m[j] = 1;
                NN--;
            } else {
                m[j] = 0;
                sumd += s[j];
            }
        }
        sumd += sum;
        // cout << "NN=" << NN << endl;
        // cout << "sumd=" << sumd << endl;

        for(j=0;j<N;j++) {
            if (m[j]) {
                d[j] = 0;
            } else {
                d[j] = 100.0*(sumd/NN-s[j])/sum;
            }
        }

        printf("Case #%d: ", i);
        for(j=0;j<N;j++) {
            if (j != 0) {
                printf(" ");
            }
            printf("%.10f", d[j]);
        }
        printf("\n");
    }
    
    return 0;
}
