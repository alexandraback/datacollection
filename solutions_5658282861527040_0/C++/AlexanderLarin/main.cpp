#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <list>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
const double EPS = 1e-9;

int T;
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("outpu.txt", "w", stdout);
    cin >> T;
    string strs[101];
    int it[101], crnt[101];
    int cnt;
    for(int Ti = 1; Ti <= T; ++Ti)
    {
        int a, b, k;
        cin >> a >> b >> k;
        int cnt = 0;
        for(int i = 0; i < b; ++i)
            for(int j = 0; j < a; ++j)
                if((i & j) < k)
                    ++cnt;
        cout << "Case #" << Ti << ": " << cnt << '\n';
    }

    return 0;
}

