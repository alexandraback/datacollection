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

void print(int i, int j, int k) {
    cout << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
}

int main()
{
    int nt;
    cin >> nt;
    for (int t=1; t<=nt; t++) {
        printf("Case #%d: ", t);
        int a,b,c,p;
        cin >> a >> b >> c >> p;
        p = min(p,c);
        cout << p*a*b << endl;
        for (int i=0; i<a; i++) {
            for (int j=0; j<b; j++) {
                for (int k=0; k<p; k++) {
                    print(i, j, (i+j+k)%c);
                }
            }
        }
    }
}
