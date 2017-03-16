#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define scd second
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 1000000000;
int Pow (int x) {
    if (x == 0) return 1;
    return 10*Pow (x-1);
}

int toint (string s, int x) {
    int ans = 0;
    int adj = 1;
    for (int i = s.size () - 1; i >= 0; i--) {
        if (s[i] == '?') {
            ans += (x%10)*adj;
            x /= 10;
        }
        else {
            ans += (s[i] - '0')*adj;
        }
        adj *= 10;
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    f (t, k) {
        string c, j;
        cin >> c >> j;
        int digsc = 0, digsj = 0;
        for (int i = 0; i < c.size (); i++) {
            if (c[i] == '?') digsc++;
        }
        for (int i = 0; i < j.size (); i++) {
            if (j[i] == '?') digsj++;
        }
        int base = 0;
        int maxi = Pow (digsc + digsj);
        int ans = OO;
        int ac = OO, aj = OO;
        while (base < maxi) {
            int ci = toint (c, base/Pow (digsj));
            int ji = toint (j, base % Pow (digsj));
            if (abs (ci - ji) < ans) {
                ans = abs (ci-ji);
                ac = ci;
                aj = ji;
            }
            else if (abs(ci-ji) == ans) {
                if (ci < ac) {
                    ac = ci;
                    aj = ji;
                }
                else if (ci == ac) {
                    if (ji < aj) {
                        aj = ji;
                    }
                }
            }
            base++;
        }
        cout << "Case #" << k+1 << ": ";
        int aux = Pow (c.size () - 1);
        while (aux > 1 && aux > ac) {
            cout << 0;
            aux/=10;
        }
        cout << ac << " ";
        aux = Pow (j.size () - 1);
        while (aux > 1 && aux > aj) {
            cout << 0;
            aux/=10;
        }
        cout << aj << endl;
    }
}
