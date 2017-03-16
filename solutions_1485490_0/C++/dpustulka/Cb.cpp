#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <list>
#include <cstring>
#include <map>

#define FOREACH(a,c) for(__typeof((c).begin()) a = (c).begin(); a != (c).end(); a++)
#define MP(i,j) make_pair(i,j)

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
typedef vector<int> VI;
typedef vector<PII> VII;

typedef pair<pair<LL, LL>, pair<LL, LL> > QI;
const int MAXX = 110;
VII A, B;
map<QI, long long> M;
int n, m;

long long get(int i, int j, LL k, LL l){
    if (i >= n || j >= m) return 0;
    if (k == -1) k = A[i].first;
    if (l == -1) l = B[j].first;
    if (M.find(MP(MP(i,j),MP(k,l))) != M.end()) return M[MP(MP(i,j), MP(k,l))];
    long long Q = 0;
    if (A[i].second == B[j].second){
        if (k == l) Q = k + get(i+1, j+1, -1, -1);
        else if (k > l) Q = l + get(i, j+1, k-l, -1);
        else Q = k + get(i+1, j, -1, l-k);
    }
    else {
        Q = max(get(i+1, j, -1, l), get(i, j+1, k, -1));
    }
    M[MP(MP(i,j), MP(k,l))] = Q;
    return Q;
}

int main(){
    int T; scanf ("%d", &T);
    for (int w = 0; w < T; w++){
        M.clear(); A.clear(); B.clear();
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++){
            LL a,b;
            scanf ("%lld %lld", &a, &b);
            A.push_back(MP(a,b));
        }
        for (int i = 0; i < m; i++){
            LL a,b;
            scanf ("%lld %lld", &a, &b);
            B.push_back(MP(a,b));
        }
        printf ("Case #%d: %lld\n", w+1, get(0,0,-1,-1));
    }
    return 0;
}
