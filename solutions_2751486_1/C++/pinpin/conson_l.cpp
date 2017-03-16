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

char S[2000000];

int
main(void)
{
    int T;
    long long i, j, k, a, b, ret;
    long long A, N, L, len, s_pos;
    vector<pair<long long,long long> > vd;

    cin >> T;

    for(i=1;i<=T;i++) {
        scanf("%s %d", S, &N);
        //        cin >> S >> N;

        vd.clear();

        //        L = S.size();
        L = strlen(S);
        len = 0;

        for(j=0;j<L;j++) {
            if (S[j] == 'a' ||
                S[j] == 'i' ||
                S[j] == 'u' ||
                S[j] == 'e' ||
                S[j] == 'o') {
                if (len >= N) {
                    vd.push_back(make_pair(j-len, len));
                }
                len = 0;
            } else {
                if (len == 0) {
                    s_pos = j;
                }
                len++;
                if ((len >= N) && (j == (L-1))) {
                    vd.push_back(make_pair(j-len+1, len));
                }
            }
        }
        for(j=0;j<vd.size();j++) {
            // cout << vd[j].first << "," << vd[j].second << endl;
        }

        ret = 0;

        for(j=0;j<vd.size();j++) {
            if (j == 0) {
                ret += (vd[0].first+1)*(L-(vd[0].first+N-1));
                // cout << "ret="  << ret << endl;
            } else {
                ret += (vd[j].first-(vd[j-1].first+vd[j-1].second-N))*(L-(vd[j].first+N-1));
                // cout << "ret="  << ret << endl;
            }
            for(k=1;k<=(vd[j].second-N);k++) {
                // cout << "k="  << k << endl;
                ret += (L-(vd[j].first+k+N)+1);
                // cout << "ret="  << ret << endl;
            }
        }
        
        cout << "Case #" << i << ": " << ret << endl;
    }
    
    return 0;
}
