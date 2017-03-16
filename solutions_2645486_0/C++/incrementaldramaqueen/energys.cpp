#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <queue>
#include <string.h>
#include <sstream>
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define mset(a,v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;

int a[10][2];

int main(void) {
    int i,j,l,t,tt;
    
    cin >> t;
    fo(tt,t) {
        memset(a, -1, sizeof(a));
        int e, r, n;
        
        cin >> e >> r >> n;
        
        int d = 0;
        a[e][d] = 0;
        
        fo(l,n) {
            int x;
            cin >> x;
            fo(i,10)
                a[i][1-d] = -1;
            fo(i,(e+1)) {
                fo(j,(i+1)) {
                    int ne = min(i - j + r, e);
                    if (a[ne][1-d] < a[i][d] + j*x) {
                        a[ne][1-d] = a[i][d] + j * x;
                    }
                }
            }
            d = 1-d;
        }

        int ans = -1;
        fo(i,10)
            ans = max(ans, a[i][d]);
        cout << "Case #" << tt + 1 << ": " << ans << endl;
    }
}
