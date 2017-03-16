// In the Name of Allah
// AD13

#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;		//	typedef unsigned long long  ull;
typedef pair <int, int> pii;//	typedef pair <double, double> pdd;
#define MP make_pair
const int INF = 2147483647, MOD = 1000*1000*1000 + 7;
const double eps = 1e-8; // (eps < 1e-15) is the fact (1e-14)
#define For(i, n) for (int i = 0; i < (n); i++)
#define For1(i, n) for (int i = 1; i <= (n); i++)
//#define debug(x) { cerr << #x << " = _" << (x) << "_" << endl; }
void Error(string err) { cout << err; cerr << "_" << err << "_"; exit(0); }
int gcd(int a, int b) { return (b==0)? a: gcd(b, a%b); }
/*-------------------------------------------------------------------------------------*/



/*_____________________________________________________________________________________*/

// check debug, read 2 times (until full!)
// think --> idea? --> really works?

int main() {
    //*
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    //*/
    int T;
    cin >> T;
    For1 (tc, T) {
        cerr << "--> " << tc << " / " << T << endl;

        int n;
        cin >> n;

        vector<pair<string, string>> v(n);
        map<string, int> cnt00, cnt01;
        bool used[3333] = { false };

        For (i, n) {
            cin >> v[i].first >> v[i].second;
            cnt00[v[i].first]++;
            cnt01[v[i].second]++;
        }

        int cntUsed = 0;
        map<string, int> cnt10, cnt11;
        For (i, n) {
            if (cnt00[v[i].first] == 1 || cnt01[v[i].second] == 1) {
                used[i] = true;
                cntUsed++;
                cnt10[v[i].first]++; cnt11[v[i].second]++;
            }
        }
        int ans = 0;
        while(cntUsed < n) {
            bool changed = false;
            For (i, n) {
                if (used[i]) continue;
                if (cnt10[v[i].first] > 0 && cnt11[v[i].second] > 0) {
                    changed = used[i] = true;
                    cntUsed++;
                    ans++;
                }
            }
            if (!changed) {
                cnt00.clear(); cnt01.clear();
                For(i, n) if (used[i] == false) {
                    cnt00[v[i].first]++; cnt01[v[i].second]++;
                }
                int best = -1;
                For (i, n) if (used[i] == false) {
                    if (best == -1 ||
                            min(cnt00[v[i].first], cnt01[v[i].second]) >
                            min(cnt00[v[best].first], cnt01[v[best].second]))
                        best = i;
                }
                used[best] = true;
                cntUsed++;
                cnt10[v[best].first]++; cnt11[v[best].second]++;
            }
        }

        cout << "Case #" << tc << ": " << ans;
        cout << endl;
    }

    return 0;
}
/*
2
3
x y
x z
a y
3
x y
x z
b y
*/
