#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/

int main() {
    ios::sync_with_stdio(false);
    freopen("A-small-attempt0.in.txt","r",stdin);
    freopen("output","w",stdout);
    int i,j,k,n,N,T,ans;
    cin >> T;
    for (int z1 = 1;z1 <= T;z1++) {
        cin >> N;
        string s;
        cin >> s;
        j = 0;
        ans = 0;
        for (i = 0;i <= N;i++) {
            k = s[i] - '0';
            if (i > j) {
                ans += (i - j);
                j = i;
            }
            j += k;
        }
        cout << "Case #" << z1 << ": " << ans << endl;
    }
    return 0;
}
