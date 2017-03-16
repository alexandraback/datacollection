#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
typedef pair <string, string> pss;
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    for (int g=1; g<=t; g++){
        cout << "Case #" << g  << ": ";
        int n; cin >> n;
        vector <pss> luv;
        for (int y=0; y<n; y++){
            string a, b; cin >> a >> b; luv.push_back(pss(a, b));
        }
        int ans = 0;
        for (int y=0; y<(1<<n); y++){
            map <string, bool> f, s;
            for (int z=0; z<n; z++){
                if ((1 << z) & y) f[luv[z].first]=1, s[luv[z].second]=1;
            }
            bool flag = true;
            for (int z=0; z<n; z++){
                if ((1 <<z) & y) continue;
                flag&=f[luv[z].first];
                flag&=s[luv[z].second];
                if (flag == 0) break;
            }
            if (flag == 0) continue;
            ans = max(ans, n - __builtin_popcount(y));
        }
        cout << ans << endl;
    }
}