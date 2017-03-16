#include <vector> // headers {{{
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>

using namespace std; // }}}

bool checkDiff(const vector<int>& v)
{
    int m = *min_element(v.begin(), v.end());
    int M = *max_element(v.begin(), v.end());

    return m >= 0 && M <= 10 && abs(m - M) <= 2;
}

bool check(int t, int p, bool s)
{
    vector<int> v(3, t / 3);
    int left = t % 3;

    for (int i = 2; i >= 0 && left; --i, --left) {
        v[i]++;
    }

    int M = *max_element(v.begin(), v.end());

    if (!s)
        return M >= p;

    vector<int> v0 = v;
    v0[0]--;
    v0[1]++;
    if (checkDiff(v0))
        M = max(M, *max_element(v0.begin(), v0.end()));

    v0 = v;
    v0[0]--;
    v0[2]++;
    if (checkDiff(v0))
        M = max(M, *max_element(v0.begin(), v0.end()));

    v0 = v;
    v0[1]--;
    v0[2]++;
    if (checkDiff(v0))
        M = max(M, *max_element(v0.begin(), v0.end()));

    return M >= p;
}

int result(int n, int s, int p, const vector<int>& t)
{
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        if (check(t[i], p, 0))
            ++cnt1;
        else if (check(t[i], p, 1))
            ++cnt2;
    }

    cnt2 = min(cnt2, s);

    return cnt1 + cnt2;
}

int main()
{
    ifstream fcin("test.in");
    ofstream fcout("test.out");
    int T;
    fcin >> T;

    for (int i = 0; i < T; ++i) {
        int N, S, p;
        fcin >> N >> S >> p;
        vector<int> v(N);
        for (int j = 0; j < N; ++j) {
            fcin >> v[j];
        }
        fcout << "Case #" << i + 1 << ": " << result(N, S, p, v) << endl;
    }

    return 0;
}
