#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <cassert>

using namespace std;

void prologue()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    FILE *fp = freopen("/Users/-RooneY-/Desktop/src/input", "r", stdin);
    assert(fp);
    
    FILE *fpw = freopen("/Users/-RooneY-/Desktop/src/output", "w", stdout);
    assert(fpw);
}

int c, w;

int GetWays(int C, int W)
{
    int x = (C+W-1)/W;
    return x + W - 1;
}

int main()
{
    prologue();
 
    int t;
    cin >> t;
    
    for (int test = 1; test <= t; ++test)
    {
        int R, C, W;
        cin >> R >> C >> W;
        
        int ans = 0;
        ans += (C/W) * (R-1);
        ans += GetWays(C, W);
        
        cout << "Case #" << test << ": " << ans << endl;
    }
    
    return 0;
}