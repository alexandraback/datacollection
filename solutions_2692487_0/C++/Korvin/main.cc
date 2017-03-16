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
#include <ctime>

#define DEBUG(x) cout << #x << ": " << x << "\n"
using namespace std; // }}}

int result(int A, vector<int> v)
{
    sort(v.begin(), v.end());
    if (A == 1)
        return v.size();
    int cnt = v.size();
    int n = v.size();
    for (int z = 0; z <= n; ++z) {
        int cur = z, AA = A;
        for (int i = 0; i < n - z; ++i) {
            while (AA <= v[i]) {
                AA+= AA - 1;
                ++cur;
            }
            AA+= v[i];
        }
        cnt = min(cnt, cur);
    }
    return cnt;
}

int main()
{
    time_t start, end;
    time(&start);
    
    ifstream cin("test.in");
    ofstream cout("test.out");
    //cout.precision(6);
    //cout.setf(ios::fixed,ios::floatfield);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int A, N;
        cin >> A >> N;
        vector<int> v(N);
        for (int j = 0; j < N; ++j)
            cin >> v[j];
        cout << "Case #" << i << ": " << result(A, v) << endl;
        time(&end);
        ::cout << i << " " << difftime(end, start) << endl;
    }

    return 0;
}
