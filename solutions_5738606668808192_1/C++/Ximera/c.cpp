#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (lol)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)


int t, n, m;
int a[100];
lol q;
vector<vector<int>> res;


void gen(int cur) {
    if(cur == 0) {
//        if(t % 100 == 0)
//            cout << t << '\n';
        t++;
        vector<int> v;
//        for(int i = n; i >= 1; i--)
//            cout << a[i];
//        cout << "\n";
        for(int i = 2; i <= 10; i++) {
            for(int j = 2; j <= 1000; j++) {
                lol q = 0, p = 1;
                for(int k = 1; k <= n; k++) {
                    q = (q + a[k] * p);
                    p = (p * i);
                }
////                cout << i << ' ' <
                if(q % j == 0) {
                    v.pb(j);
                    break;
                }
//                break;

            }

            if(v.size() != i - 1)
                break;
        }
        if(v.size() == 9) {
            m--;
            res.pb(v);
//            for(int i = 2; i <= 10; i++) {
//                lol q = 0;
//                for(int j = n; j >= 1; j--) {
//                    q = q * i + a[j];
//                }
//                cout << q << "\t";
//            }
//            cout << "\n";
            for(int i = n; i >= 1; i--)
                cout << a[i];
            cout << " ";
            for(auto x: v)
                cout << x << ' ';
            cout << "\n";
        }
//        cout << m << "\n";
        if(m == 0)
            exit(0);
//        exit(0);
    } else {
        a[cur] = 0;
        if(cur != n && cur != 1)
            gen(cur - 1);
        a[cur] = 1;
        gen(cur - 1);
    }
}

int main() {
    inp("input.txt");
    out("output.txt");
    scanf("%d%d%d", &t, &n, &m);
    printf("Case #1:\n");
    gen(n);
    return 0;
}

