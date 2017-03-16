#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

int bf(int E_cur, int E_orig, int R, vector<int> &act, int offset=0)
{
    if(offset >= act.size()) return 0;
    
    int max_ = 0;
    for(int e = 0; e <= E_cur; ++e)
    {
        int result = bf(min(E_cur - e + R, E_orig), E_orig, R, act, offset+1) + e * act[offset];
        max_ = max(max_, result);
    }
    
    return max_;
}

void testcase(int tst)
{
    int E, R, N;
    cin >> E >> R >> N;
    vector<int> act;
    for(int n = 0; n < N; ++n)
    {
        int v_n;
        cin >> v_n;
        act.push_back(v_n);
    }
    cout << "Case #" << tst << ": " << bf(E,E,R,act) << endl;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        testcase(t);
    }
    return 0;
}
