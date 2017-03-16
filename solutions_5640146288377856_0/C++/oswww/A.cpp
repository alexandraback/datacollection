#define OSW2

#include <iostream>
#include <functional>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;




int main() {
#ifdef OSW
    freopen("//Users//osw//Desktop//in.txt", "r", stdin);
#endif
#ifdef OSW2
    string file_name = "A-small-attempt1";
    freopen(("//Users//osw//Downloads//" + file_name + ".in").c_str(), "r", stdin);
    freopen(("//Users//osw//Downloads//" + file_name + ".out").c_str(), "w", stdout);
#endif
    
    int T, t = 0;
    cin >> T;

    while (T-(t++)) {
        int R,C,W;
        cin >> R >> C >> W;
        int ans;
        if (W==1) ans = R*C;
        else {
            ans = R*( C/W );
            //cout << C/W << ' ' << ans << endl;
            if (C%W==0) {
                ans += W-1;
            } else {
                ans += W;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}



