#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cmath> 
#include <ctime> 
#include <float.h> 

using namespace std; 

#define REP(i, from, to) for (int i = (from); i < (to); ++i) 
#define FOR(i, n) REP(i, 0, (n)) 
#define ALL(x) x.begin(), x.end() 
#define SIZE(x) (int)x.size() 
#define PB push_back 
#define MP make_pair 

typedef long long i64; 
typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef vector<string> VS; 
typedef vector<VS> VVS; 
typedef pair<i64, i64> PII; 

i64 getCount(vector<PII> const& toys, int type, int l, int size) {
    i64  res = 0;
    REP (i, l, l + size)
        if (toys[i].second == type)
            res += toys[i].first;
    return res;
}

i64 getCount(vector<PII> const& toys, int type) {
    return getCount(toys, type, 0, SIZE(toys));
}



int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    FOR (tt, t) {
        int n, m;
        cin >> n >> m;

        vector<PII> a(n), b(m);
        FOR (i, n) cin >> a[i].first >> a[i].second;
        FOR (i, m) cin >> b[i].first >> b[i].second;

        vector<PII> boxes_, toys;
        i64 cnt = 0;

        if (n == 0 || m == 0)
            goto calc;

        cnt = 0;
        FOR (i, m + 1) {
            if (i != m && (i == 0 || b[i].second == b[i - 1].second))
                cnt += b[i].first;
            else {
                toys.PB(MP(cnt, b[i - 1].second));
                if (i != m) cnt = b[i].first;
            }
        }

calc:
        i64 res = 0;

        REP (mask, 1, 1 << SIZE(a)) {
            vector<PII> boxes;
            FOR (i, SIZE(a))
                if (mask & (1 << i))
                    boxes.PB(a[i]);

            vector<PII> newBoxes;
            i64 cnt = 0;
            FOR (i, SIZE(boxes) + 1) {
                if (i != SIZE(boxes) && (i == 0 || boxes[i].second == boxes[i - 1].second))
                    cnt += boxes[i].first;
                else {
                    newBoxes.PB(MP(cnt, boxes[i - 1].second));
                    if (i != SIZE(boxes)) cnt = boxes[i].first;
                }
            }

            boxes = newBoxes;
            
            if (SIZE(boxes) == 1) {
                res = max(res, min(boxes[0].first, getCount(toys, boxes[0].second)));
            } else if (SIZE(boxes) == 2) {
                FOR (i, SIZE(toys) + 1) {
                    int const j = SIZE(toys) - i;
                    if (j < 0) continue;
                
                    int x = 0;
                    i64 cnt = 0;
                    if (i) {
                        cnt += min(boxes[0].first, getCount(toys, boxes[0].second, x, i));
                        x += i;
                    }

                    if (j) {
                        cnt += min(boxes[1].first, getCount(toys, boxes[1].second, x, j));
                        x += j;
                    }

                    res = max(res, cnt);
                }
            } else {
                FOR (i, SIZE(toys) + 1) FOR (j, SIZE(toys) + 1) {
                    int const k = SIZE(toys) - i - j;
                    if (k < 0) continue;

                    int x = 0;
                    i64 cnt = 0;
                    if (i) {
                        cnt += min(boxes[0].first, getCount(toys, boxes[0].second, x, i));
                        x += i;
                    }

                    if (j) {
                        cnt += min(boxes[1].first, getCount(toys, boxes[1].second, x, j));
                        x += j;
                    }

                    if (k) {
                        cnt += min(boxes[2].first, getCount(toys, boxes[2].second, x, k));
                        x += k;
                    }

                    res = max(res, cnt);
                }
            }
        }

        printf("Case #%d: ", tt + 1);
        cout << res << endl;
    }
    
    return 0;
}