#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cstdio>
using namespace std;

int R, E, MAXE, N, T;
vector<int> v;

int calc(int start) {
    if (start == N) return 0;
    int maxr = 0;
    for (int i = 0; i <= E; i++) {
        int oldE = E;
        E -= i;
        E += R;
        if (E > MAXE) E = MAXE;
        int res = v[start]*i + calc(start+1);
        if (res > maxr) {
            maxr = res;
        }
        E = oldE;
    }
    return maxr;
}


int main()
{
    int T; cin >> T;
    for (int I = 1; I <= T; I++) {
        int res = 0;
        cin >> MAXE >> R >> N;
        E = MAXE;
        v.clear();
        for (int i = 0; i < N; i++) {
            int t; cin >> t; v.push_back(t);
        }
        res = calc(0);
        cout << "Case #" << I << ": " << res << endl;
    }
}
