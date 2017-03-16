#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _T;
    cin >> _T;
    for(int T = 0; T < _T; T++){
        int D;
        cin >> D;
        int P[D];
        for(int i = 0; i < D; i++) cin >> P[i];
        int ans = 10000000;
        for(int i = 1; i < 1002; i++){
            int temp = i;
            for(int j = 0; j < D; j++){
                temp += P[j] / i;
                if(P[j] % i == 0) temp--;
            }
            ans = min(ans,temp);
        }
        cout << "Case #" << T+1<< ": " << ans << "\n";
    }
    return 0;
}

