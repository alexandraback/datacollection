#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void print(int i){cout << i << " ";}
void print(string s){cout << s << endl;}
template<class T> void print(vector<T> v){for(int i=0;i<v.size();++i)print(v[i]);cout << endl;}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tt;
    scanf("%d", &tt);
    for (int qq=1;qq<=tt;qq++)
    {
        printf("Case #%d: ", qq);

        int n;
        cin >> n;
        vector<string> inp(n);
        for(int i=0;i<n;++i)
            cin >> inp[i];

        vector<vector<int> > ints(n);
        for(int i=0;i<n;++i)
        {
            int chain=1;
            for(int j=1;j<inp[i].size();++j)
                if(inp[i][j]==inp[i][j-1])
                    chain++;
                else
                {
                    ints[i].push_back(chain);
                    chain=1;
                }
            ints[i].push_back(chain);
        }

        for(int i=0;i<n;++i)
            inp[i].erase(unique(inp[i].begin(),inp[i].end()),inp[i].end());

        bool feg=false;
        for(int i=0;i<n && !feg;++i)
            if(inp[i]!=inp[0])
                feg=true;

        if(feg)
        {
            cout << "Fegla Won" << endl;
        }
        else
        {
            int totmoves = 0;
            for(int i=0;i<ints[0].size();++i)
            {
                int bestmoves=9999999;
                for(int m=1;m<101;++m)
                {
                    int curmoves = 0;
                    for(int j=0;j<n;++j)
                    {
                        curmoves += abs(ints[j][i]-m);
                    }
                    bestmoves = min(bestmoves,curmoves);
                }
                totmoves+=bestmoves;
            }
            cout << totmoves << endl;
        }
    }
}













