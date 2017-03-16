#include <bits/stdc++.h>

#define pii pair<int, int>
#define pdd pair<double, double>
#define ull unsigned long long
#define uint unsigned int
#define ll long long
#define INF 999999999
#define LINF 999999999999999999
#define M 1000000007
#define E 0.0000001
#define N (1<<17)

using namespace std;



int main() {
    ifstream in("google.in");
    ofstream out("google.out");

    int n;
    in>>n;

    for (int c = 1; c <= n; c++) {
        int t;
        in>>t;
        string f[t];
        string s[t];
        int ans = 0;
        for (int i = 0; i < t; i++) {
            in>>f[i]>>s[i];
        }
        for (int i = 0; i < (1<<t); i++) {
            unordered_map<string, int> fm;
            unordered_map<string, int> sm;
            int x = 0;
            for (int j = 0; j < t; j++) {
                if (i & (1<<j)) {
                    fm[f[j]] = 1;
                    sm[s[j]] = 1;
                    x++;
                }
            }
            bool b = true;
            for (int j = 0; j < t; j++) {
                if (!(i & (1<<j))) {
                    if (fm[f[j]] && sm[s[j]]) {

                    } else {
                        b = false;
                        break;
                    }
                }
            }
            if (b) ans = max(ans, t - x);
        }
        out<<"Case #"<<c<<": "<<ans<<endl;
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }

    out.close();
    return 0;
}
