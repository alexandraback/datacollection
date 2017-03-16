#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define y1 stupid_y1
#define ll long long
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define file ""

const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);

int main () {
    freopen("a.in", "r", stdin);
    freopen("a2.out", "w", stdout);

    int t;
    scanf("%d", &t);

    string s;
    for (int ii=0;ii<t;ii++){
        cin >>s;
        printf("Case #%d: ", ii+1);
        string res = s.substr(0, 1);
        for (int i=1;i<s.length();i++){
            if (s[i] >= res[0]){
                string t = "";
                t += s[i];
                t += res;
                res = t;
            }
            else res += s[i];
        }
        cout <<res<<endl;
    }


    #ifdef LOCAL
    cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif

    return 0;
}