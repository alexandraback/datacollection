#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>


using namespace std;
#define ll long long

string A[1000], B[1000];
int An[1000], Bn[1000];
int N;

int solve() {
    map<string, int> lu;
    set<int> Aw, Bw;
    for (int i=0;i<N;++i) {
        if (lu.count(A[i]) == 0) {
            int z = lu.size();
            lu[A[i]] = z;
        }
        An[i] = lu[A[i]];
        Aw.insert(An[i]);
    }
    for (int i=0;i<N;++i) {
        if (lu.count(B[i]) == 0) {
            int z = lu.size();
            lu[B[i]] = z;
        }
        Bn[i] = lu[B[i]];
        Bw.insert(Bn[i]);
    }

    int ans = 0;
    for (int i=0;i<(1<<N);++i) {
        set<int> Af, Bf;
        int gc = 0;
        for (int j=0;j<N;++j) {
            if (i & (1<<j)) {
                Af.insert(An[j]);
                Bf.insert(Bn[j]);
                ++gc;
            }
        }

        if (Af.size() == Aw.size() && Bf.size() == Bw.size()) {
            ans = max(ans, N - gc);
        }
    }
    return ans;
}

int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        cin>>N;
        for (int i=0;i<N;++i) {
            cin>>A[i]>>B[i];
        }

        int ans = solve();

        printf("Case #%d: %d\n", t, ans);
    }

}
