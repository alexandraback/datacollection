#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

ll pow2(ll n) {
    int p = 1;
    for (int i=0; i<n; i++)
        p *= 2;
    return p;
}

int main()
{
    int nt;
    cin >> nt;
    for (int t=1; t<=nt; t++) {
        printf("Case #%d: ", t);
        ll b,m;
        cin >> b >> m;
        if (m > pow2(b-2))
            cout << "IMPOSSIBLE" << endl;
        else {
            cout << "POSSIBLE" << endl << '0';
            for (int i=1; i<b; i++) {
                if (m >= pow2(b-2-i)) {
                    cout << '1';
                    m -= pow2(b-2-i);
                }
                else cout << '0';
            }
            cout << endl;
            for (int i=1; i<b; i++) {
                int j;
                for (j=0; j<=i; j++) cout << '0';
                for (; j<b; j++) cout << '1';
                cout << endl;
            }
        }
    }
}
