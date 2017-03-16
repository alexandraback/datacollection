#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int solve(int R, int C, int W)
{
    //check the last position of each group of w cells
    int ans = C/W;
    ans += W - 1;
    if(C%W){
        //one extra missing
        ans ++;
    }
    return ans*R;
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    //55
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++){
        //R=1 C[1, 10] W[1, C]
        int R, C, W;
        cin >> R >> C >> W;
        cout << "Case #" << cas << ": " << solve(R, C, W) << endl;
    }
    return 0;
}
