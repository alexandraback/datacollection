#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll B, M;
    cin >> B >> M;

    int slides[B][B] = {0};

    for(int i = 1; i < B; i++)
        slides[0][i] = 1;

    if(M > (1<<(B-2)))
    {
        cout << "IMPOSSIBLE";
        return;
    }
    //M -= 1;

    int a = -1;
    int b = -1;
    for(b = 61; b >= 0; b--)
    {
        if((1LL<<b) & M)
        {
            a = B - b - 2;
            for(int x = a + 1; x < B - 1; x++)
            {
                for(int y = x+1; y < B; y++)
                    slides[x][y] = 1;
            }
            break;
        }
    }
    M -= (1LL << b);
    //b -= 1;
    for( ; b >= 1; b--)
    {
        //cerr << "a " << a << " M " << M << " b " << b << "\n";
        if((1LL<<(b-1)) & M)
        {
            slides[a][B - b - 1] = 1;
            M -= (1LL<<(b-1));
        }
    }
    
    cout << "POSSIBLE\n";
    for(int x = 0; x < B; x++)
    {
        for(int y = 0; y < B; y++)
            cout << slides[x][y];
        cout << "\n";
    }

}

int main()
{
    cout.precision(8);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

