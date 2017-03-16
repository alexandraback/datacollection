#include <bits/stdc++.h>

#define pii pair<int, int>
#define pdd pair<double, double>
#define ull unsigned long long
#define uint unsigned int
#define ll long long
#define ld long double
#define INF 999999999
#define LINF 999999999999999999
#define M 1000000007
#define E 0.0000001
#define N (1<<18)

#define cout out
#define cin in

using namespace std;

int main() {
    ofstream out("google.out");
    ifstream in("google.in");

    int t;
    cin>>t;

    for (int c = 1; c <= t; c++) {
        int j, p, s, k;
        cin>>j>>p>>s>>k;
        if (j == 3 && p == 3 && s == 3) {
            if (k == 2) {
                int ans = 62580637;
                cout<<"Case #"<<c<<": "<<18<<endl;
                for (int j = 0; j < 27; j++) {
                    if (ans & (1<<j)) {
                        int x = j % s;
                        int y = (j / s) % p;
                        int z = (j / s / p);
                        x++; y++; z++;
                        cout<<z<<" "<<y<<" "<<x<<endl;
                    }
                }
                continue;
            } else if (k >= 3) {
                int ans = (1<<27) - 1;
                cout<<"Case #"<<c<<": "<<27<<endl;
                for (int j = 0; j < 27; j++) {
                    if (ans & (1<<j)) {
                        int x = j % s;
                        int y = (j / s) % p;
                        int z = (j / s / p);
                        x++; y++; z++;
                        cout<<z<<" "<<y<<" "<<x<<endl;
                    }
                }
                continue;
            }
        }
        int f = j * p * s;
        int ans = 0;
        int m = 0;
        vector<int> fail;
        for (int i = 1; i < (1<<f); i++) {
            bool asd = true;
            for (int p : fail) {
                if ((p & i) == p) {
                    asd = false;
                    break;
                }
            }
            if (!asd) continue;
            int a = 0;
            bool b = true;
            unordered_map<int, int> g;

            for (int j = 0; j < f; j++) {
                if (i & (1<<j)) {
                    a++;
                    int x = j % s;
                    int y = (j / s) % p;
                    int z = (j / s / p);
                    x++;
                    y++;
                    z++;
                    g[x + 1000 * y]++;
                    g[1000 * y + 1000000 * z]++;
                    g[x + 1000000 * z]++;
                    if (g[x + 1000 * y] > k || g[1000 * y + 1000000 * z] > k || g[x + 1000000 * z] > k) {
                        b = false;
                        fail.push_back(i);
                        break;
                    }
                }
            }
            if (b) {
                if (a > m) {
                    m = a;
                    ans = i;
                }
            }
        }
        cout<<"Case #"<<c<<": "<<m<<endl;
        for (int j = 0; j < f; j++) {
            if (ans & (1<<j)) {
                int x = j % s;
                int y = (j / s) % p;
                int z = (j / s / p);
                x++; y++; z++;
                cout<<z<<" "<<y<<" "<<x<<endl;
            }
        }
    }

    out.close();
}
