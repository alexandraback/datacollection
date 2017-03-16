// INCLUDE LIST
#include <cstdio>
#include <bitset>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

// DEFINE LIST
#define REP(_I, _J, _K) for(_I = (_J) ; _I < (_K) ; _I++)
#define input(_A)       freopen(_A, "r", stdin);
#define output(_A)      freopen(_A, "w", stdout);
#define INPUT           input("in.txt");
#define OUTPUT          output("out.txt");
#define hold            {fflush(stdin); getchar();}
#define reset(_A, _B)   memset((_A), (_B), sizeof (_A));
#define debug           printf("<<TEST>>\n");
#define eps             1e-11
#define f_cmp(_A, _B)   (fabs((_A) - (_B)) < eps)
#define phi             acos(-1)
#define pb              push_back
#define value(_A)       cout << "Variabel -> " << #_A << " -> " << _A << endl;
#define st              first
#define nd              second

// TYPEDEF LIST
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef unsigned long long       LL;

// VAR LIST
int x4[4] =             {0, 1, 0, -1};
int y4[4] =             {1, 0, -1, 0};
int x8[8] =             {0, 1, 1,  1,  0, -1, -1, -1};
int y8[8] =             {1, 1, 0, -1, -1, -1,  0,  1};
int i, j, k;

LL get_value(LL A, LL N, LL B) {
    return (N * (2ll * A + ((N - 1ll) * B))) / 2ll;
}

LL MAX(LL A, LL B) {
    if (A > B) return A;
    else return B;
}

LL MIN(LL A, LL B) {
    if (A < B) return A;
    else return B;
}

// MAIN CODE
int main () {
    input("A-large.in");
    OUTPUT;
    int T, kasus = 0;
    cin >> T;
    while (T--) {
        LL r, t, luas_awal;
        cin >> r >> t;
        luas_awal = r + (r + 1ll);
        LL L = 0, R = MIN(1000000000ll, (t / luas_awal)), mid, ans = 0ll;
        while (L <= R) {
            mid = (L + R) / 2ll;
            LL value = get_value(luas_awal, mid, 4ll);
            if (value <= t) {
                ans = MAX(ans, mid);
                L = mid + 1;
            }
            else R = mid - 1ll;
        }
        cout << "Case #" << ++kasus << ": " << ans << endl;
    }
    return 0;
}

// VINCENTIUS MADYA
// DARKSTALKER
// LANGUAGE : C++
