#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define foreach(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

#define MAX_E 5
#define MAX_N 10
int E, R, N;
VI v;
int dp[MAX_N + 1][MAX_E + 1];

int solve(int s, int e)
{
    int& ret = dp[s][e];
    if (ret >= 0)
        return ret;
    
    ret = 0;
    for (int i = 0; i <= e; i++) {
        ret = max(ret, v[s] * i + solve(s + 1, min(E, e - i + R)));
    }

    return ret;
}

int main(int argc, const char* argv[])
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> E >> R >> N;
        v.clear();
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        memset(dp, -1, sizeof(dp));
        for (int j = 0; j < MAX_E + 1; j++)
            dp[N][j] = 0;
        cout << "Case #" << i << ": " << solve(0, E) << endl;
    }
    return 0;
}
