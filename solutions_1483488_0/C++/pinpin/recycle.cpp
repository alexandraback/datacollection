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
    int i, j, k, n, dig, m, nn;
    long long sum;
    int T, A, B;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> A >> B;
        sum = 0;
        dig = 0;
        n = A;
        nn = 1;
        while (n > 0) {
            dig++;
            n /= 10;
            nn *= 10;
        }
        nn /= 10;
        for(n=A;n<=B;n++) {
            m = n;
            for(j=1;j<dig;j++) {
                m = (m / 10) + (m % 10)*nn;
                if (m == n)
                    break;
                if (n < m && m <= B) {
                    sum++;
                }
            }
        }
        cout << "Case #" << i << ": " << sum << endl;
    }
    
    return 0;
}
