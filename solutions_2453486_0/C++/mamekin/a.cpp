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

string solve(vector<string>& s)
{
    bool draw = true;

    for(int y=0; y<4; ++y){
        for(int x=0; x<4; ++x){
            if(s[y][x] == '.')
                draw = false;

            for(int i=0; i<4; ++i){
                int a = 0;
                int b = 0;
                
                int y2 = y;
                int x2 = x;
                while(0 <= y2 && y2 < 4 && 0 <= x2 && x2 < 4){
                    if(s[y2][x2] == 'X' || s[y2][x2] == 'T')
                        ++ a;
                    if(s[y2][x2] == 'O' || s[y2][x2] == 'T')
                        ++ b;
                    y2 += dy[i];
                    x2 += dx[i];
                }

                if(a == 4)
                    return "X won";
                else if(b == 4)
                    return "O won";
            }
        }
    }

    if(draw)
        return "Draw";
    else
        return "Game has not completed";
}

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; ++i){
        vector<string> s(4);
        for(int j=0; j<4; ++j)
            cin >> s[j];

        cout << "Case #" << i << ": " << solve(s) << endl;
    }
}