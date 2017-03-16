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

int n;
vector<int> open;
vector<vector<int> > inside; 

vector<int> memo;
vector<int> ret;

bool solve(bitset<20> bs, vector<int> key)
{
    if(bs.count() == n)
        return true;
    if(memo[bs.to_ulong()])
        return false;
    memo[bs.to_ulong()] = true;

    for(int i=0; i<n; ++i){
        if(bs[i])
            continue;
        if(key[open[i]] == 0)
            continue;

        -- key[open[i]];
        for(unsigned j=0; j<inside[i].size(); ++j)
            ++ key[inside[i][j]];
        bs[i] = true;

        if(solve(bs, key)){
            ret.push_back(i);
            return true;
        }

        bs[i] = false;
        for(unsigned j=0; j<inside[i].size(); ++j)
            -- key[inside[i][j]];
        ++ key[open[i]];
    }

    return false;
}

int main()
{
    int t;
    cin >> t;

    for(int i=1; i<=t; ++i){
        int m;
        cin >> m >> n;

        vector<int> key(41, 0);
        while(--m >= 0){
            int a;
            cin >> a;
            ++ key[a];
        }

        open.resize(n);
        inside.resize(n);
        for(int j=0; j<n; ++j){
            cin >> open[j] >> m;
            inside[j].resize(m);
            for(int k=0; k<m; ++k)
                cin >> inside[j][k];
        }

        ret.clear();
        memo.assign(1<<n, false);
        if(!solve(0, key)){
            cout << "Case #" << i << ": IMPOSSIBLE" << endl;
        }else{
            cout << "Case #" << i << ':';
            for(int i=n-1; i>=0; --i)
                cout << ' ' << (ret[i] + 1);
            cout << endl;
        }
    }

    return 0;
}