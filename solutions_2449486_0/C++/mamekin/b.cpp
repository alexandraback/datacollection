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

int dy[] = {-1, 0, 1, 1};
int dx[] = {1, 1, 1, 0};

string solve()
{
    int h, w;
    cin >> h >> w;

    vector<vector<int> > s(h, vector<int>(w));
    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            cin >> s[i][j];
        }
    }

    vector<bool> checkY(h, false);
    vector<bool> checkX(w, false);
    int checkNum = h + w;

    for(int a=1; a<=100; ++a){
        for(int y=0; y<h; ++y){
            if(checkY[y])
                continue;

            bool ok = true;
            for(int x=0; x<w; ++x){
                if(s[y][x] != -1 && s[y][x] != a)
                    ok = false;
            }

            if(ok){
                for(int x=0; x<w; ++x)
                    s[y][x] = -1;
                checkY[y] = true;
                -- checkNum;
            }
        }

        for(int x=0; x<w; ++x){
            if(checkX[x])
                continue;

            bool ok = true;
            for(int y=0; y<h; ++y){
                if(s[y][x] != -1 && s[y][x] != a)
                    ok = false;
            }

            if(ok){
                for(int y=0; y<h; ++y)
                    s[y][x] = -1;
                checkX[x] = true;
                -- checkNum;
            }
        }
    }

    if(checkNum == 0)
        return "YES";
    else
        return "NO";
}

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; ++i)
        cout << "Case #" << i << ": " << solve() << endl;

    return 0;
}