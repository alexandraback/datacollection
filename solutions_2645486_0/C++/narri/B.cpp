#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct Solver {
    typedef map<int, long long> MEMO;
    MEMO memo[10005];
    long long things[10005];
    int N;
    int E, R;
    long long dp(int at, int curr_e)
    {
        if(at == N){return 0;}
        MEMO::iterator iter = memo[at].find(curr_e);
        if(iter != memo[at].end()){return iter->second;}
        long long out = 0;
        for(int i=0;i<=curr_e;++i)
        {
            out = max(out, things[at] * i + dp(at+1, min(E, curr_e - i + R)));
        }
        return memo[at][curr_e] = out;
    }
    long long doit(int ee, int rr, const vector<int> &vals)
    {
        N = vals.size();
        for(int i=0;i<N;++i)
        {things[i] = vals[i];}
        E = ee;
        R = rr;
        return dp(0, E);
    }
};

int main(int argc, char **argv)
{
    if(argc > 1){freopen(argv[1], "r", stdin);}
    int CASES;
    cin >> CASES;
    for(int cn=1;cn<=CASES;++cn)
    {
        Solver *solver = new Solver();
        int E, R, T;
        cin >> E >> R >> T;
        vector<int> v(T, 0);
        for(int i=0;i<T;++i){cin >> v[i];}
        long long ret = solver->doit(E, R, v);
        delete solver;
        printf("Case #%d: %lld\n", cn, ret);
    }
    return 0;
}

