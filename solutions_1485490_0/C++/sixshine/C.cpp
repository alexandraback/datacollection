#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <list>
#include <functional>
#include <utility>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h);i>(l);--i)
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ifstream cin("D:\\in.txt");
    ofstream cout("D:\\out.txt");
    freopen("D:\\in.txt", "r", stdin);
    freopen("D:\\out.txt", "w", stdout);
    int T;
    cin >> T;
    REP(i,T) {
        int N, M;
        cin >> N >> M;
        vector<LL> La(N), Lb(M);
        VI Ca(N), Cb(M);
        REP(j,N) {
            cin >> La[j] >> Ca[j];
        }
        REP(j,M) {
            cin >> Lb[j] >> Cb[j];
        }
        if (N == 3) {
            if (Ca[2] == Ca[1]) {
                La[1] += La[2];
                N = 2;
            } else if (Ca[1] == Ca[0]) {
                La[0] += La[1];
                La[1] = La[2];
                Ca[1] = Ca[2];
                N = 2;
            }
        }
        if (N == 2) {
            if (Ca[1] == Ca[0]) {
                La[0] += La[1];
                N = 1;
            }
        }
        LL ans = 0;
        if (N == 1) {
            LL cnt = 0;
            REP(j,M) {
                if (Cb[j] == Ca[0]) {
                    cnt += Lb[j];
                }
            }
            if (cnt > La[0]) {
                ans = La[0];
            } else {
                ans = cnt;
            }
        } else if (N == 2) {
            LL cnt1 = 0;
            REP(j,M) {
                if (Cb[j] == Ca[1]) {
                    cnt1 += Lb[j];
                }
            }
            if (cnt1 > La[1]) {
                cnt1 = La[1];
            }
            if (cnt1 > ans) {
                ans = cnt1;
            }
            LL cnt0 = 0;
            REP(j,M) {
                if (Cb[j] == Ca[0]) {
                    cnt0 += Lb[j];
                }
                if (cnt0 > La[0]) {
                    cnt0 = La[0];
                }
                LL cnt1 = 0;
                for (int k = j + 1; k < M; ++k) {
                    if (Cb[k] == Ca[1]) {
                        cnt1 += Lb[k];
                    }
                }
                if (cnt1 > La[1]) {
                    cnt1 = La[1];
                }
                if (cnt0 + cnt1 > ans) {
                    ans = cnt0 + cnt1;
                }
            }
        } else {
            if (Ca[2] == Ca[0]) {
                LL cnt = 0;
                REP(j,M) {
                    if (Cb[j] == Ca[0]) {
                        cnt += Lb[j];
                    }
                }
                if (cnt > La[0] + La[2]) {
                    ans = La[0] + La[2];
                } else {
                    ans = cnt;
                }
            }
            LL cnt2 = 0;
            REP(j,M) {
                if (Cb[j] == Ca[2]) {
                    cnt2 += Lb[j];
                }
            }
            if (cnt2 > La[2]) {
                cnt2 = La[2];
            }
            if (cnt2 > ans) {
                ans = cnt2;
            }
            LL cnt1 = 0;
            REP(j,M) {
                if (Cb[j] == Ca[1]) {
                    cnt1 += Lb[j];
                }
                if (cnt1 > La[1]) {
                    cnt1 = La[1];
                }
                LL cnt2 = 0;
                for (int k = j + 1; k < M; ++k) {
                    if (Cb[k] == Ca[2]) {
                        cnt2 += Lb[k];
                    }
                }
                if (cnt2 > La[2]) {
                    cnt2 = La[2];
                }
                if (cnt1 + cnt2 > ans) {
                    ans = cnt1 + cnt2;
                }
            }
            LL cnt0 = 0;
            REP(j,M) {
                if (Cb[j] == Ca[0]) {
                    cnt0 += Lb[j];
                }
                if (cnt0 > La[0]) {
                    cnt0 = La[0];
                }
                LL cnt2 = 0;
                for (int k = j + 1; k < M; ++k) {
                    if (Cb[k] == Ca[2]) {
                        cnt2 += Lb[k];
                    }
                }
                if (cnt2 > La[2]) {
                    cnt2 = La[2];
                }
                if (cnt0 + cnt2 > ans) {
                    ans = cnt0 + cnt2;
                }
                LL cnt1 = 0;
                for (int k = j + 1; k < M; ++k) {
                    if (Cb[k] == Ca[1]) {
                        cnt1 += Lb[k];
                    }
                    if (cnt1 > La[1]) {
                        cnt1 = La[1];
                    }
                    LL cnt2 = 0;
                    for (int p = k + 1; p < M; ++p) {
                        if (Cb[p] == Ca[2]) {
                            cnt2 += Lb[p];
                        }
                    }
                    if (cnt2 > La[2]) {
                        cnt2 = La[2];
                    }
                    if (cnt0 + cnt1 + cnt2 > ans) {
                        ans = cnt0 + cnt1 + cnt2;
                    }
                }
            }
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}
