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

string S;

int
main(void)
{
    int T;
    int i, j, k, a, b, ret;
    int A, N, L;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> S >> N;

        L = S.size();

        ret = 0;
        for(j=0;j<L;j++) {
            for(k=j+N;k<=L;k++) {
                for(a=j;a<=(k-N);a++) {
                    bool flg = true;
                    for(b=0;b<N;b++) {
                        // cout << "j,k,a,b=" << j << "," << k << "," << a << "," << b << "," << endl;
                        if (S[a+b] == 'a' ||
                            S[a+b] == 'i' ||
                            S[a+b] == 'u' ||
                            S[a+b] == 'e' ||
                            S[a+b] == 'o') {
                            flg = false;
                            break;
                        }
                    }
                    if (flg) {
                        // cout << "here" << endl;
                        ret++;
                        break;
                    }
                }
            }
        }
        
        cout << "Case #" << i << ": " << ret << endl;
    }
    
    return 0;
}
