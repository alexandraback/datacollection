//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 105
#define maxX 2500

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int nTest, n, cnt[maxX+1];

bool isLess (vector<int> a, vector<int> b) {
    fto(i, 0, n-1) {
        if (a[i] >= b[i]) return false;
    }
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof cnt);
        fto(i, 1, 2*n-1) {
            fto(j, 1, n) {
                int x;
                scanf("%d", &x);
                ++cnt[x];
            }
        }

        printf("Case #%d:", iTest);
        fto(i, 1, maxX) {
            if (cnt[i]%2 == 1) printf(" %d", i);
        }
        puts("");
    }


    return 0;
}
