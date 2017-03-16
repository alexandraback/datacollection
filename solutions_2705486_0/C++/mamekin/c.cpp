#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

const int INF = INT_MAX / 4;

string s;
int n;

pair<int, int> check(int i, string& word, int prev)
{
    if(n - i < word.size())
        return make_pair(-1, -1);

    int change = 0;
    for(int j=0; j<word.size(); ++j){
        if(s[i+j] != word[j]){
            if(i+j - prev < 5)
                return make_pair(-1, -1);
            prev = i + j;
            ++ change;
        }
    }
    return make_pair(change, prev);
}

int main()
{
    int m = 521196;
    vector<string> word(m);
    for(int i=0; i<m; ++i)
        cin >> word[i];

    int t;
    cin >> t;

    for(int tc=1; tc<=t; ++tc){
        cin >> s;
        n = s.size();

        vector<vector<int> > dp(n+1, vector<int>(n+1, INF));
        dp[0][0] = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<=i; ++j){
                for(int k=0; k<m; ++k){
                    pair<int, int> p;
                    if(j == 0){
                        p = check(i, word[k], -INF);
                    }else{
                        p = check(i, word[k], j-1);
                    }

                    if(p.first != -1){
                        int i2 = i + word[k].size();
                        int j2 = max(0, p.second + 1);
                        dp[i2][j2] = min(dp[i2][j2], dp[i][j] + p.first);
                    }
                }
            }
        }

        int ret = INF;
        for(int i=0; i<=n; ++i)
            ret = min(ret, dp[n][i]);
        cout << "Case #" << tc << ": " << ret << endl;
    }
}