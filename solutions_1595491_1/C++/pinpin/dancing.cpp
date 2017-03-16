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
    int N, S, P;
    int i, j;
    int pnt;
    int c_ok, c_ng, sum;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> N >> S >> P;
        c_ok = c_ng = 0;
        for(j=0;j<N;j++) {
            cin >> pnt;
            if ((pnt < (P+P-2+P-2)) || (pnt < P)) {
                c_ng++;
            } else if (pnt >= (P+P-1+P-1)) {
                c_ok++;
            }
        }
        sum = c_ok + min(N-c_ok-c_ng,S);

        cout << "Case #" << i << ": " << sum << endl;
    }
    
    return 0;
}
