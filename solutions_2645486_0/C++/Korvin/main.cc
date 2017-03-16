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

int doit(int E, int R, const vector<int>& v, int idx, int curE)
{
    int N = v.size();
    if (idx == N)
        return 0;
    int res = 0;
    for (int i = 0; i <= curE; ++i) {
        int cur = i * v[idx] + doit(E, R, v, idx + 1, min(curE - i + R, E));
        res = max(res, cur);
    }
    return res;
}

int result(int E, int R, const vector<int>& v)
{
    int N = v.size();
    int res = doit(E, R, v, 0, E);
}

int main()
{
    //time_t start, end;
    //time(&start);
    
    ifstream cin("test.in");
    ofstream cout("test.out");
    //cout.precision(6);
    //cout.setf(ios::fixed,ios::floatfield);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int E, R, N;
        cin >> E >> R >> N;
        vector<int> v(N);
        for (int j = 0; j < N; ++j)
            cin >> v[j];
        cout << "Case #" << i << ": " << result(E, R, v) << endl;
        //time(&end);
        //::cout << i << " " << difftime(end, start) << endl;
    }

    return 0;
}
