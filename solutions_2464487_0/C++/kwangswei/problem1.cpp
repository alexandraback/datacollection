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

int main() {
    int T;
    cin >> T;


    for (int i = 1; i <= T; i++)
    {
        int r, t;
        cin >> r >> t;

        int cnt = 0;
        t -= (r+1)*(r+1) - r*r;
        while ( t >= 0 ) {
            cnt++;
            t -= ((r+(cnt*2)+1) * (r+(cnt*2)+1) - (r+cnt*2) * (r+cnt*2));
        }
        cout << "Case #" << i << ": " << cnt << endl;
    }

    return 0;
}
