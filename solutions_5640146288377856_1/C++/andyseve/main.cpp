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
    int _T;
    scanf("%d",&_T);
    for(int T = 0; T < _T; T++){
        cout << "Case #" << T+1 << ": ";
        int R, C, W;
        scanf("%d%d%d",&R,&C,&W);
        int ans = 0;
        ans += R * (C/W);
        ans += W;
        if(C % W == 0) ans--;
        cout << ans << "\n";
    }
    return 0;
}
