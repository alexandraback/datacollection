#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
using namespace std;

typedef long long ll;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-9;

int calc(int A, const vector<int> &v, int end) {
    int ret = 0;
    for (int i=0; i<end; ++i) {
        while(A <= v[i]) {
            ret++;
            A += A-1;
        }
        A += v[i];
    }
    return ret;
}

int solve() {
    int A,N;
    cin>>A>>N;
    vector<int> in(N);
    for (int i=0; i<N; ++i) cin>>in[i];
    sort(in.begin(), in.end());

    if (A == 1) return N;
    int ans = INF;
    for (int end=0; end<=N; ++end) {
        int removed = N-end;
        ans = min(ans, removed + calc(A, in, end));
    }
    return ans;
}

int main() {
    int T;
    cin>>T;
    for (int tc=1; tc <= T; ++tc) {
        cout<<"Case #"<<tc<<": "<<solve()<<endl;;
    }
}
