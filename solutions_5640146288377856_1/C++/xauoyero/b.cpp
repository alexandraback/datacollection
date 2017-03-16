#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int solve(int R, int C, int W)
{
    //check the last position of each group of w cells
    //ans < C*R + C + W <= C*R + 2*C <= 440 
    int ans = C/W;
    //each missing row try C/W times
    ans += (C/W)*(R - 1);
    ans += W - 1;
    if(C%W){
        //one extra missing
        ans ++;
    }
    return ans;
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    //[1, 100]
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++){
        //R=[1, 20] C[1, 20] W[1, C]
        int R, C, W;
        cin >> R >> C >> W;
        cout << "Case #" << cas << ": " << solve(R, C, W) << endl;
    }
    return 0;
}
