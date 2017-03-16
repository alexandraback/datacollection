#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>inline string to_str(const T& v) {
    ostringstream os; os << v; return os.str();
}
template<typename T>inline T to_obj(const string& v) {
    istringstream is(v); T r; is>>r; return r;
}
template<class T>inline int cMin(T& a, T b) {return b<a ? a=b,1 : 0;}
template<class T>inline int cMax(T& a, T b) {return a<b ? a=b,1 : 0;}

#define CLR(A,v) memset(A, v, sizeof(A))
#define MP(a,b)  make_pair(a, b)
#define F0(i, n) for(int i=0; i<(n); ++i)
#define F1(i, n) for(int i=1; i<=(n); ++i)

typedef std::pair<int, int> PII;
typedef std::pair<int, PII> Node;

int countBit(int n) {
    int ans = 0;
    for(; n>0; n&=n-1) ans++;
    return ans;
}

int rr(int J, int P, int S, int K) {
    if (J * P * S > 20) return -1;
    vector<Node> A;
    F0(j, J) F0(p, P) F0(s, S) {
        A.push_back(Node(j, PII(p, s)));
    }
    const int N = A.size();
    int bitEnd = 1<<N;
    int best = 0;
    for(int bit=1; bit<bitEnd; ++bit) {
        if (countBit(best) > countBit(bit)) continue;
        int maskJP[4][4] = {0};
        int maskJS[4][4] = {0};
        int maskPS[4][4] = {0};
        F0(i, N) if ((bit>>i) & 1) {
            maskJP[A[i].first][A[i].second.first]++;
            maskJS[A[i].first][A[i].second.second]++;
            maskPS[A[i].second.first][A[i].second.second]++;
        }
        bool tag = true;
        F0(i, 4) F0(j, 4) {
            if (maskJP[i][j] > K || maskJS[i][j] > K || maskPS[i][j] > K) {
                tag = false;
                break;
            }
        }
        if (tag) {
            if (countBit(best) < countBit(bit)) best = bit;
        }
    }
    return countBit(best);
}

bool check(const vector<Node>& A, int K) {
    int maskJP[4][4] = {0};
    int maskJS[4][4] = {0};
    int maskPS[4][4] = {0};
    F0(i, A.size()) {
        maskJP[A[i].first][A[i].second.first]++;
        maskJS[A[i].first][A[i].second.second]++;
        maskPS[A[i].second.first][A[i].second.second]++;
    }
    bool tag = true;
    F0(i, 4) F0(j, 4) {
        if (maskJP[i][j] > K || maskJS[i][j] > K || maskPS[i][j] > K) {
            return false;
        }
    }
    return true;
}

int maskJP[10][10] = {0};
int maskJS[10][10] = {0};
int maskPS[10][10] = {0};
vector<Node> calc(int J, int P, int S, int K) {
    F0(i, 10) F0(j, 10) maskJP[i][j] = maskJS[i][j] = maskPS[i][j] = 0;
    memset(maskJP, 0, sizeof(maskJP));
    int mask[4][4][4] = {0};
    int s = S-1;
    vector<Node> ans;
    F0(j, J) F0(p, P) {
        int n = std::min(K - maskJP[j][p], S);
        int cc = 0;
        F0(z, n) {
            int& jp = maskJP[j][p];
            int& js = maskJS[j][s];
            int& ps = maskPS[p][s];
            s = (s + 1) % S;
            if (jp >= K || js >= K || ps >= K || mask[j][p][s]) {
                ++n;
                ++cc;
                if (cc >= S || cc > K) break;
                continue;
            }
            mask[j][p][s] = 1;
            ++jp; ++js; ++ps;
            ans.push_back(Node(j+1, PII(p+1, s+1)));
        }
    }
    return ans;
}

int main(int argc, char *argv[]) {
    int T; scanf("%d", &T);
    F1(Ti, T) {
        int J, P, S, K;
        scanf("%d%d%d%d", &J, &P, &S, &K);
        vector<Node> ans = calc(J, P, S, K);
        int z = rr(J, P, S, K);
        if (z > 0 && z != ans.size()) {
            printf("Error: %d %d %d %d  cur[%d] right[%d]\n",
                   J, P, S, K,
                   (int)ans.size(), z);
            throw std::runtime_error("invalid");
        }
        if (!check(ans, K)) {
            printf("Error: %d %d %d %d  cur[%d] right[%d]\n",
                   J, P, S, K,
                   (int)ans.size(), z);
            throw std::runtime_error("invalid");
        }
        printf("Case #%d: %d\n", Ti, (int)ans.size());
        F0(i, ans.size()) {
            printf("%d %d %d\n",
                   ans[i].first, ans[i].second.first,
                   ans[i].second.second);
        }
    }
    return 0;
}
