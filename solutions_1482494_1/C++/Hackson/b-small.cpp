#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define eps 1e-9
#define FOR(x, s, e) for(int x = (s); x < (e); ++x)
#define FORc(x, s, e, c) for(int x = (s); x < (e) && (c); ++x)
#define STEP(x, s, e, d) for(int x = (s); x < (e); x+=(d))
#define ROF(x, s, e) for(int x = (s); x >= (e); --x)
#define ROFc(x, s, e, c) for(int x = (s); x >= (e) && (c); --x)
#define vb vector<bool>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define ALL(X) X.begin(), X.end()
#define LL long long
#define pii pair<int, int>
#define x first
#define y second
#define gcd(x, y) __gcd((x), (y))
#define countbit(x) __builtin_popcount(x)

using namespace std;

int main(int argc, char **argv){
    int T;
    cin >> T;
    FOR(ca, 1, T+1){
        printf("Case #%d: ", ca);
        int N;
        cin >> N;
        pii A[N];
        bool done[N];
        memset(done, 0, sizeof(done));
        FOR(i, 0, N) cin >> A[i].x >> A[i].y;
        FOR(i, 0, N-1)
            ROF(j, i, 0)
                if (A[j].y > A[j+1].y) swap(A[j], A[j+1]);
                else if (A[j].y == A[j+1].y && A[j].x > A[j+1].x)
                    swap(A[j], A[j+1]);
        int res = 0, star = 0;
        bool ok = 1;
        FORc(i, 0, N, ok){
            if (done[i] && star >= A[i].y) res++, star++;
            //else if (done[i] && star < A[i].y) ok = 0;
            else if (star >= A[i].y){
                res++, star += 2;
            }else{
                int pos = -1;
                FOR(j, i, N)
                    if (star >= A[j].x && !done[j])
                        if (pos == -1) pos = j;
                        else if (A[j].y > A[pos].y)
                            pos = j;
                if (pos == -1) ok = 0;
                else{
                    done[pos] = 1;
                    res++, star++;
                    --i;
                }
            }
        }
        if (!ok) puts("Too Bad");
        else printf("%d\n", res);
    }
	return 0;
}
