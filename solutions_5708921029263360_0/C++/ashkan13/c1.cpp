// In the Name of Allah
// AD13

#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
#define For1(i, n) for (int i = 1; i <= (n); i++)
/*-------------------------------------------------------------------------------------*/

struct { int a, b, c; } arr[10000];

char temp[10];
string strAns[1000];

bool used[1000];

int n, ans;
int a, b, c, mostCnt;

bool isGood() {
    vector<int> cnt(1000);
    For (ind, n) {
        if (used[ind]) {
            int i = arr[ind].a, j = arr[ind].b, k = arr[ind].c;
            cnt[i * 100 + j * 10]++;
            cnt[i * 100 + k]++;
            cnt[j * 10 + k]++;
            if (cnt[i * 100 + j * 10] > mostCnt) return false;
            if (cnt[i * 100 + k] > mostCnt) return false;
            if (cnt[j * 10 + k] > mostCnt) return false;
        }
    }
    return true;
}

void f (int ind)
{
    if (ind == n) {
        int cnt = 0;
        For (i, ind) {
            if (used[i]) cnt++;
        }
        if (cnt > ans && isGood()) {
            ans = cnt;
            cnt = 0;
            For (i, n) {
                if (used[i]) {
                    itoa(arr[i].a, temp, 10);
                    strAns[cnt] = temp;
                    itoa(arr[i].b, temp, 10);
                    strAns[cnt] += " "; strAns[cnt] += temp;
                    itoa(arr[i].c, temp, 10);
                    strAns[cnt] += " "; strAns[cnt] += temp;
                    cnt++;
                }
            }
        }
        return;
    }
    used[ind] = true;
    f (ind + 1);
    used[ind] = false;
    f (ind + 1);
}

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

        cin >> a >> b >> c >> mostCnt;

        For(i, 1000) used[i] = false;

        n = 0;
        For1 (i, a) {
            For1 (j, b) {
                For1 (k, c) {
                    arr[n].a = i;
                    arr[n].b = j;
                    arr[n].c = k;
                    n++;
                }
            }
        }

        ans = 0;
        f (0);

        cout << "Case #" << tc << ": " << ans << endl;
        For (i, ans) cout << strAns[i] << endl;
    }

    return 0;
}
/*
4
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1

*/
