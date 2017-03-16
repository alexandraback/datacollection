#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second

using namespace std;
const int MAXN = 1005;

int t, n;
double num;
vector <double> naomi, ken;
vector <pair <double, int> > nk;
          
int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        naomi.clear();
        ken.clear();
        nk.clear();
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> num;
            naomi.puba(num);
            nk.puba(mapa(num, 0));
        }
        for (int j = 0; j < n; ++j) {
            cin >> num;
            ken.puba(num);
            nk.puba(mapa(num, 1));
        }
        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());
        sort(nk.begin(), nk.end());
        int lk = 0, rk = n - 1;
        int ans1 = 0, ans2 = 0;
        for (int j = 0; j < n; ++j) {            
            //cout << naomi[j] << " " << ken[j] << endl;
            if (ken[lk] < naomi[j]) {
                ++ans1;
                ++lk; 
            } else {
                --rk;
            }
        }
        int balr = 0, ball = 0;
        for (int j = 2 * n - 1; j >= 0; --j) {
            if (nk[j].ss == 1) {
                ++balr;
            } else {
                if (balr == 0) {
                    ++ans2;
                    ++ball;
                } else {
                    --balr;
                }
            }
        }
        cout << "Case #" << i + 1 << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}