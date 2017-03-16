#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <stack>
#include <cstdlib>

using namespace std;

#define MAX_N 3
#define MAX_M 5
#define MAX_K 7

int r, n, m, k;
set<int> product;


string solve() {
    char result[1000];
    for (int i = MAX_M; i >1; i-- ) {
        for (int j = MAX_M; j > 1; j--) {
            for (int q = MAX_M; q > 1; q--) {
                bool sw = true;
                for (int p = 0; p < k; p++)
                {
                    if ( product.find(i * j * q) == product.end() )
                    {
                        sw = false;
                        break;
                    }
                }

                if (sw)
                {
                    sprintf(result, "%d%d%d", i, j, q);
               
                    return result;
                }
            }
        }
    }

    return "222";
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        cin >> r >> n >> m >> k;

        cout << "Case #" << i << ": " << endl;
        for ( int q = 0; q < r; q++) {
            product = set<int>();
            for (int j = 0; j < k; j++)
            {
                int num;
                cin >> num;
                product.insert(num);
            }
        cout << solve() << endl;
        }
    }

    return 0;
}
